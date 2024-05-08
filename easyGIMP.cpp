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
	if (img.type() != CV_8UC3)
	{
		throw gcnew System::NotSupportedException("Only images of type CV_8UC3 are supported for conversion to Bitmap");
	}

	//create the bitmap and get the pointer to the data
	System::Drawing::Imaging::PixelFormat fmt(System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	System::Drawing::Bitmap^ bmpimg = gcnew System::Drawing::Bitmap(img.cols, img.rows, fmt);

	System::Drawing::Imaging::BitmapData^ data = bmpimg->LockBits(System::Drawing::Rectangle(0, 0, img.cols, img.rows), System::Drawing::Imaging::ImageLockMode::WriteOnly, fmt);

	byte* dstData = reinterpret_cast<byte*>(data->Scan0.ToPointer());

	unsigned char* srcData = img.data;

	for (int row = 0; row < data->Height; ++row)
	{
		memcpy(reinterpret_cast<void*>(&dstData[row * data->Stride]), reinterpret_cast<void*>(&srcData[row * img.step]), img.cols * img.channels());
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

