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
	this->label_for_Canny->Visible = true;
	this->play_Canny->Visible = true;
	this->input_kernel_size->Visible = true;
	this->input_lower_threshold->Visible = true;
	this->input_upper_threshold->Visible = true;

	this->lable_for_resize->Visible = false;
	this->play_resize->Visible = false;
	this->input_height->Visible = false;
	this->input_width->Visible = false;
	this->changingType2->Visible = false;
	this->kernelsize2->Visible = false;
	this->erosion_go_button->Visible = false;
	this->label_for_erosion->Visible = false;
	this->changingType->Visible = false;
	this->kernelsize->Visible = false;
	this->dilate_go_button->Visible = false;
	this->label_for_dilation->Visible = false;

}

System::Void Project::easyGIMP::Turn_gray_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->img->undoAll();
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
	this->img->blur(3);
	displayCVImage(img);

}

System::Void Project::easyGIMP::resize_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->lable_for_resize->Visible = true;
	this->play_resize->Visible = true;
	this->input_height->Visible = true;
	this->input_width->Visible = true;

	this->label_for_Canny->Visible = false;
	this->play_Canny->Visible = false;
	this->input_kernel_size->Visible = false;
	this->input_lower_threshold->Visible = false;
	this->input_upper_threshold->Visible = false;
	this->changingType2->Visible = false;
	this->kernelsize2->Visible = false;
	this->erosion_go_button->Visible = false;
	this->label_for_erosion->Visible = false;
	this->changingType->Visible = false;
	this->kernelsize->Visible = false;
	this->dilate_go_button->Visible = false;
	this->label_for_dilation->Visible = false;
}

System::Void Project::easyGIMP::input_OnFocus(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::TextBox^ textBox = dynamic_cast<System::Windows::Forms::TextBox^>(sender);

	if (textBox != nullptr)
	{
		textBox->Text = "";
	}
}

System::Void Project::easyGIMP::play_Click(System::Object^ sender, System::EventArgs^ e)
{
	checkImageDentified();

	System::String^ height = this->input_height->Text;
	System::String^ width = this->input_width->Text;


	double h = 0;
	double w = 0;
	try
	{
		h = System::Double::Parse(height);
		w = System::Double::Parse(width);

		this->img->resize(0, 0, cv::Size(w, h));
		resizePictureBox(img);
		displayCVImage(img);
	}
	catch (System::FormatException^ e)
	{
		MessageBox::Show("The height and width should be rational numbers: " + e->Message);
	}

	this->lable_for_resize->Visible = false;
	this->play_resize->Visible = false;
	this->input_height->Visible = false;
	this->input_width->Visible = false;
	this->changingType2->Visible = false;
	this->kernelsize2->Visible = false;
	this->erosion_go_button->Visible = false;
	this->label_for_erosion->Visible = false;
	this->changingType->Visible = false;
	this->kernelsize->Visible = false;
	this->dilate_go_button->Visible = false;
	this->label_for_dilation->Visible = false;

	this->input_height->Text = "Height:";
	this->input_width->Text = "Width:";


}

void Project::easyGIMP::checkImageDentified()
{
	if (this->img == nullptr) {
		MessageBox::Show("There is no image.");
		return;
	}
}

System::Void Project::easyGIMP::play_Canny_Click(System::Object^ sender, System::EventArgs^ e)
{
	checkImageDentified();

	System::String^ kernelSize = this->input_kernel_size->Text;
	System::String^ upperThreshold = this->input_upper_threshold->Text;
	System::String^ lowerThreshold = this->input_lower_threshold->Text;



	int ks = 0;
	int uth = 0;
	int lth = 0;
	try
	{
		ks = System::Int32::Parse(kernelSize);
		if (ks % 2 == 0) {
			MessageBox::Show("The size of the kernel must be the odd number.");
		}

		uth = System::Int32::Parse(upperThreshold);
		lth = System::Int32::Parse(lowerThreshold);

		this->img->undoAll();
		this->img->detectEdges(ks, uth, lth);

		displayCVImage(img);
	}
	catch (System::FormatException^ e)
	{
		MessageBox::Show("The kernel size, upper threshold and lower threshold should be integer: " + e->Message);
	}


	this->label_for_Canny->Visible = false;
	this->play_Canny->Visible = false;
	this->input_kernel_size->Visible = false;
	this->input_lower_threshold->Visible = false;
	this->input_upper_threshold->Visible = false; 
	this->changingType2->Visible = false;
	this->kernelsize2->Visible = false;
	this->erosion_go_button->Visible = false;
	this->label_for_erosion->Visible = false;
	this->changingType->Visible = false;
	this->kernelsize->Visible = false;
	this->dilate_go_button->Visible = false;
	this->label_for_dilation->Visible = false;

	this->input_kernel_size->Text = "Kernel size:";
	this->input_lower_threshold->Text = "Lower threshold:";
	this->input_upper_threshold->Text = "Upper threshold:";

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

System::Void Project::easyGIMP::Erode_Click(System::Object^ sender, System::EventArgs^ e) {


	this->changingType2->Visible = true;
	this->kernelsize2->Visible = true;
	this->erosion_go_button->Visible = true;
	this->label_for_erosion->Visible = true;


	this->lable_for_resize->Visible = false;
	this->play_resize->Visible = false;
	this->input_height->Visible = false;
	this->input_width->Visible = false;
	this->label_for_Canny->Visible = false;
	this->play_Canny->Visible = false;
	this->input_kernel_size->Visible = false;
	this->input_lower_threshold->Visible = false;
	this->input_upper_threshold->Visible = false;
	this->changingType->Visible = false;
	this->kernelsize->Visible = false;
	this->dilate_go_button->Visible = false;
	this->label_for_dilation->Visible = false;

	
}

System::Void Project::easyGIMP::Dilate_Click(System::Object^ sender, System::EventArgs^ e) {

	this->changingType->Visible = true;
	this->kernelsize->Visible = true;
	this->dilate_go_button->Visible = true;
	this->label_for_dilation->Visible = true;

	this->lable_for_resize->Visible = false;
	this->play_resize->Visible = false;
	this->input_height->Visible = false;
	this->input_width->Visible = false;
	this->label_for_Canny->Visible = false;
	this->play_Canny->Visible = false;
	this->input_kernel_size->Visible = false;
	this->input_lower_threshold->Visible = false;
	this->input_upper_threshold->Visible = false;
	this->changingType2->Visible = false;
	this->kernelsize2->Visible = false;
	this->erosion_go_button->Visible = false;
	this->label_for_erosion->Visible = false;

}


System::Void Project::easyGIMP::DilateReal_Click(System::Object^ sender, System::EventArgs^ e) {
	
	checkImageDentified();

	System::String^ kernelSize = this->kernelsize->Text;
	System::String^ changingType = this->changingType->Text;

	this->lable_for_resize->Visible = false;
	this->play_resize->Visible = false;
	this->input_height->Visible = false;
	this->input_width->Visible = false;
	this->label_for_Canny->Visible = false;
	this->play_Canny->Visible = false;
	this->input_kernel_size->Visible = false;
	this->input_lower_threshold->Visible = false;
	this->input_upper_threshold->Visible = false;
	this->changingType2->Visible = false;
	this->kernelsize2->Visible = false;
	this->erosion_go_button->Visible = false;
	this->label_for_erosion->Visible = false;


	int ks = 0;
	int ct = 0;
	try
	{
		ks = System::Int32::Parse(kernelSize);
		ct = System::Int32::Parse(changingType);

		this->img->undoAll();
		this->img->dilation(ct, ks);

		displayCVImage(img);
	}
	catch (System::FormatException^ e)
	{
		MessageBox::Show("The kernel size and dilation type should be integer: " + e->Message);
	}

}

System::Void Project::easyGIMP::ErodeReal_Click(System::Object^ sender, System::EventArgs^ e) {

	checkImageDentified();

	System::String^ kernelSize = this->kernelsize2->Text;
	System::String^ changingType = this->changingType2->Text;

	this->lable_for_resize->Visible = false;
	this->play_resize->Visible = false;
	this->input_height->Visible = false;
	this->input_width->Visible = false;
	this->label_for_Canny->Visible = false;
	this->play_Canny->Visible = false;
	this->input_kernel_size->Visible = false;
	this->input_lower_threshold->Visible = false;
	this->input_upper_threshold->Visible = false;


	int ks = 0;
	int ct = 0;
	try
	{
		ks = System::Int32::Parse(kernelSize);
		ct = System::Int32::Parse(changingType);

		this->img->undoAll();
		this->img->erosion(ct, ks);

		displayCVImage(img);
	}
	catch (System::FormatException^ e)
	{
		MessageBox::Show("The kernel size and erotion type should be integer: " + e->Message);
	}
}