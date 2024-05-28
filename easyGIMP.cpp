#include "easyGIMP.h"


inline System::Void Project::easyGIMP::easyGIMP_Load(System::Object^ sender, System::EventArgs^ e) {
}

inline System::Void Project::easyGIMP::easyGIMP_Enter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
	if (e->Data->GetDataPresent(DataFormats::FileDrop))
		e->Effect = DragDropEffects::Copy;
	else
		e->Effect = DragDropEffects::None;
}

bool IsImageExtension(System::String^ extension) {
	// Define an array of image file extensions
	array<System::String^>^ imageExtensions = {
		"jpg", "jpeg", "png", "gif", "bmp", "tiff"
	};

	// Convert the input extension to lowercase to make the comparison case-insensitive
	extension = extension->ToLower();

	// Check if the given extension is in the array of image extensions
	return System::Array::IndexOf(imageExtensions, extension) != -1;  // or use imageExtensions->Contains(extension) if using System::Linq
}

System::Drawing::Bitmap^ ConvertCvMatToBitmap(cv::Mat& img) {
	if (img.type() != CV_8UC3 && img.type() != CV_8UC1)
	{
		throw gcnew System::NotSupportedException("Only images of type CV_8UC3 and CV_8UC1 are supported for conversion to Bitmap");
	}

	System::Drawing::Imaging::PixelFormat fmt;
	if (img.type() == CV_8UC3) {
		fmt = System::Drawing::Imaging::PixelFormat::Format24bppRgb;
	}
	else if (img.type() == CV_8UC1) {
		fmt = System::Drawing::Imaging::PixelFormat::Format8bppIndexed;
	}

	System::Drawing::Bitmap^ bmpimg = gcnew System::Drawing::Bitmap(img.cols, img.rows, fmt);

	System::Drawing::Imaging::BitmapData^ data = bmpimg->LockBits(System::Drawing::Rectangle(0, 0, img.cols, img.rows), System::Drawing::Imaging::ImageLockMode::WriteOnly, fmt);

	byte* dstData = reinterpret_cast<byte*>(data->Scan0.ToPointer());
	unsigned char* srcData = img.data;

	if (img.type() == CV_8UC3) {
		for (int row = 0; row < data->Height; ++row) {
			memcpy(reinterpret_cast<void*>(&dstData[row * data->Stride]), reinterpret_cast<void*>(&srcData[row * img.step]), img.cols * img.channels());
		}
	}
	else if (img.type() == CV_8UC1) {
		// Set up the grayscale palette
		System::Drawing::Imaging::ColorPalette^ palette = bmpimg->Palette;
		for (int i = 0; i < 256; i++) {
			palette->Entries[i] = System::Drawing::Color::FromArgb(i, i, i);
		}
		bmpimg->Palette = palette;

		for (int row = 0; row < data->Height; ++row) {
			memcpy(reinterpret_cast<void*>(&dstData[row * data->Stride]), reinterpret_cast<void*>(&srcData[row * img.step]), img.cols * img.channels());
		}
	}

	bmpimg->UnlockBits(data);

	return bmpimg;
}

void Project::easyGIMP::displayCVImage(MyImage* img) {
	if (img == nullptr) throw gcnew System::ArgumentException("Empty Mat");
	// Convert the cv::Mat from MyImage to System::Drawing::Bitmap
	cv::Mat cvImage = img->getCVMat();
	System::Drawing::Bitmap^ bitmap = ConvertCvMatToBitmap(cvImage);

	if (bitmap != nullptr) {
		this->pictureBox->Image = bitmap;
	}
}


inline System::Void Project::easyGIMP::easyGIMP_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
	//get the file name
	String^ pathToFile = dynamic_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop))[0];
	//get the extension
	array<String^>^ substrings = pathToFile->Split({ '.' });

	//convert pathToFile type from System::String^ to cv::String
	msclr::interop::marshal_context context;
	const cv::String& path = context.marshal_as<std::string>(pathToFile);

	//if It's an image create img instance 
	if (IsImageExtension(substrings[substrings->Length - 1])) {
		img = new MyImage(path);

		this->pictureBox->Size = img->getSize();
		displayCVImage(img);
	}

	this->Save->Visible = true;
}

System::Void Project::easyGIMP::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (openImageDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		//get the file name
		String^ pathToFile = System::IO::Path::GetDirectoryName(openImageDialog->FileName);

		//get the extension
		array<String^>^ substrings = pathToFile->Split({ '.' });

		//convert pathToFile type from System::String^ to cv::String
		msclr::interop::marshal_context context;
		const cv::String& path = context.marshal_as<std::string>(pathToFile);
		//if It's an image create img instance 
		if (IsImageExtension(substrings[substrings->Length - 1])) {
			img = new MyImage(path);

			this->pictureBox->Size = img->getSize();
			displayCVImage(img);
		}

		this->Save->Visible = true;
	}
}

void Project::easyGIMP::resizePictureBox(MyImage* img)
{
	this->pictureBox->Size = img->getSize();
}

inline System::Void Project::easyGIMP::scaleUp(System::Object^ sender, System::EventArgs^ e) {
	this->img->scaleUp();
	resizePictureBox(img);
	displayCVImage(img);
}

inline System::Void Project::easyGIMP::scaleDown(System::Object^ sender, System::EventArgs^ e) {
	this->img->scaleDown();
	resizePictureBox(img);
	displayCVImage(img);
}

System::Void Project::easyGIMP::Detect_edges_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->img->undoAll();
	this->img->detectEdges();
	displayCVImage(img);
}

System::Void Project::easyGIMP::Turn_gray_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->img->turngGray();
	displayCVImage(img);
}

System::Void Project::easyGIMP::Undo_all_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->img->undoAll();
	displayCVImage(img);
}

System::Void Project::easyGIMP::Save_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		std::string path;
		FolderBrowserDialog^ folderBrowserDialog = gcnew FolderBrowserDialog();
		if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			System::String^ folderPath = folderBrowserDialog->SelectedPath;

			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->InitialDirectory = folderPath;
			saveFileDialog->Filter = "All files (*.*)|*.*";
			saveFileDialog->Title = "Specify File Name";

			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				System::String^ filePath = saveFileDialog->FileName;
				// Convert System::String^ to std::string
				path = msclr::interop::marshal_as<std::string>(filePath);
				MessageBox::Show(gcnew System::String(path.c_str()), "Selected File Path");
			}
		}
		this->img->save(path);
		MessageBox::Show(gcnew System::String(path.c_str()), "File Saved", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	catch (const std::exception& e) {
		return;
	}
	
}

System::Void Project::easyGIMP::Blur_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->img->blur();
	displayCVImage(img);

}

System::Void Project::easyGIMP::contrastAndBrightnessButton_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Decimal decimalBeta = brightnessInput->Value;
	double betaDouble = decimalBeta.ToDouble(decimalBeta);

	System::Decimal decimalAlpha = contrastInput->Value;
	double alphaDouble = decimalAlpha.ToDouble(decimalAlpha);

	img->brightnessAndContrastControl(alphaDouble, betaDouble);
	displayCVImage(img);
}

System::Void Project::easyGIMP::rgbButton_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Decimal decimalR = redInput->Value;
	double rDouble = decimalR.ToDouble(decimalR);

	System::Decimal decimalG = greenInput->Value;
	double gDouble = decimalG.ToDouble(decimalG);

	System::Decimal decimalB = blueInput->Value;
	double bDouble = decimalB.ToDouble(decimalB);

	img->rgbControl(rDouble, gDouble, bDouble);
	displayCVImage(img);

}




