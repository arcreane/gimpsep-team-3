#pragma once
#include <iostream>
#include <vcclr.h>
#include <msclr/marshal_cppstd.h>

#include "MyImage.h"





namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for easyGIMP
	/// </summary>
	public ref class easyGIMP : public System::Windows::Forms::Form
	{
	public:

		MyImage* img;

		easyGIMP(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~easyGIMP()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox;







	private: System::Windows::Forms::NumericUpDown^ contrastInput;
	private: System::Windows::Forms::GroupBox^ contrastAndBrightnessBox;
	private: System::Windows::Forms::Label^ brightnessLabel;
	private: System::Windows::Forms::Label^ contrastLabel;
	private: System::Windows::Forms::Button^ contrastAndBrightnessButton;
	private: System::Windows::Forms::TextBox^ input_height;
	private: System::Windows::Forms::TextBox^ input_width;
	private: System::Windows::Forms::Button^ play_resize;

	private: System::Windows::Forms::NumericUpDown^ brightnessInput;
	private: System::Windows::Forms::NumericUpDown^ redInput;
	private: System::Windows::Forms::GroupBox^ rgbBox;


	private: System::Windows::Forms::NumericUpDown^ blueInput;
	private: System::Windows::Forms::NumericUpDown^ greenInput;
	private: System::Windows::Forms::Label^ blueLabel;
	private: System::Windows::Forms::Label^ greenLabel;
	private: System::Windows::Forms::Label^ redLabel;
	private: System::Windows::Forms::Button^ rgbButton;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ zoomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ zoomPlusToolStripMenuItem2;



	private: System::Windows::Forms::ToolStripMenuItem^ undoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ undoAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ blurToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ turnGrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ detectEdgesToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openImageDialog;

	private: System::ComponentModel::IContainer^ components;



	private: System::Windows::Forms::Label^ lable_for_resize;
	private: System::Windows::Forms::Button^ resize;
	private: System::Windows::Forms::Label^ label_for_Canny;
	private: System::Windows::Forms::TextBox^ input_upper_threshold;
	private: System::Windows::Forms::TextBox^ input_lower_threshold;
	private: System::Windows::Forms::TextBox^ input_kernel_size;
	private: System::Windows::Forms::ToolStripMenuItem^ resizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ zoomMinusToolStripMenuItem1;
	private: System::Windows::Forms::GroupBox^ edegeDetectionBox;
	private: System::Windows::Forms::GroupBox^ resizeBox;
	private: System::Windows::Forms::ToolStripMenuItem^ rGBToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ contrastBrightnessToolStripMenuItem;



	private: System::Windows::Forms::Button^ play_Canny;












	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->contrastInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->contrastAndBrightnessBox = (gcnew System::Windows::Forms::GroupBox());
			this->contrastAndBrightnessButton = (gcnew System::Windows::Forms::Button());
			this->brightnessInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->brightnessLabel = (gcnew System::Windows::Forms::Label());
			this->contrastLabel = (gcnew System::Windows::Forms::Label());
			this->redInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->rgbBox = (gcnew System::Windows::Forms::GroupBox());
			this->rgbButton = (gcnew System::Windows::Forms::Button());
			this->blueLabel = (gcnew System::Windows::Forms::Label());
			this->greenLabel = (gcnew System::Windows::Forms::Label());
			this->redLabel = (gcnew System::Windows::Forms::Label());
			this->blueInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->greenInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomPlusToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomMinusToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blurToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->turnGrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->detectEdgesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rGBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contrastBrightnessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openImageDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->input_height = (gcnew System::Windows::Forms::TextBox());
			this->input_width = (gcnew System::Windows::Forms::TextBox());
			this->play_resize = (gcnew System::Windows::Forms::Button());
			this->label_for_Canny = (gcnew System::Windows::Forms::Label());
			this->input_upper_threshold = (gcnew System::Windows::Forms::TextBox());
			this->input_lower_threshold = (gcnew System::Windows::Forms::TextBox());
			this->input_kernel_size = (gcnew System::Windows::Forms::TextBox());
			this->play_Canny = (gcnew System::Windows::Forms::Button());
			this->edegeDetectionBox = (gcnew System::Windows::Forms::GroupBox());
			this->resizeBox = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contrastInput))->BeginInit();
			this->contrastAndBrightnessBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brightnessInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->redInput))->BeginInit();
			this->rgbBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blueInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenInput))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->edegeDetectionBox->SuspendLayout();
			this->resizeBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(151, 62);
			this->pictureBox->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(175, 286);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &easyGIMP::easyGIMP_DragDrop);
			this->pictureBox->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &easyGIMP::easyGIMP_Enter);
			// 
			// contrastInput
			// 
			this->contrastInput->DecimalPlaces = 1;
			this->contrastInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->contrastInput->Location = System::Drawing::Point(3, 58);
			this->contrastInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->contrastInput->Name = L"contrastInput";
			this->contrastInput->Size = System::Drawing::Size(86, 20);
			this->contrastInput->TabIndex = 8;
			this->contrastInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// contrastAndBrightnessBox
			// 
			this->contrastAndBrightnessBox->Controls->Add(this->contrastAndBrightnessButton);
			this->contrastAndBrightnessBox->Controls->Add(this->brightnessInput);
			this->contrastAndBrightnessBox->Controls->Add(this->brightnessLabel);
			this->contrastAndBrightnessBox->Controls->Add(this->contrastLabel);
			this->contrastAndBrightnessBox->Controls->Add(this->contrastInput);
			this->contrastAndBrightnessBox->Location = System::Drawing::Point(2, 40);
			this->contrastAndBrightnessBox->Name = L"contrastAndBrightnessBox";
			this->contrastAndBrightnessBox->Size = System::Drawing::Size(92, 155);
			this->contrastAndBrightnessBox->TabIndex = 9;
			this->contrastAndBrightnessBox->TabStop = false;
			this->contrastAndBrightnessBox->Text = L"Contrast and Brightness";
			this->contrastAndBrightnessBox->Visible = false;
			// 
			// contrastAndBrightnessButton
			// 
			this->contrastAndBrightnessButton->Location = System::Drawing::Point(3, 124);
			this->contrastAndBrightnessButton->Name = L"contrastAndBrightnessButton";
			this->contrastAndBrightnessButton->Size = System::Drawing::Size(85, 23);
			this->contrastAndBrightnessButton->TabIndex = 12;
			this->contrastAndBrightnessButton->Text = L"Apply";
			this->contrastAndBrightnessButton->UseVisualStyleBackColor = true;
			this->contrastAndBrightnessButton->Click += gcnew System::EventHandler(this, &easyGIMP::contrastAndBrightnessButton_Click);
			// 
			// brightnessInput
			// 
			this->brightnessInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->brightnessInput->Location = System::Drawing::Point(3, 97);
			this->brightnessInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->brightnessInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, System::Int32::MinValue });
			this->brightnessInput->Name = L"brightnessInput";
			this->brightnessInput->Size = System::Drawing::Size(85, 20);
			this->brightnessInput->TabIndex = 11;
			// 
			// brightnessLabel
			// 
			this->brightnessLabel->AutoSize = true;
			this->brightnessLabel->Location = System::Drawing::Point(4, 81);
			this->brightnessLabel->Name = L"brightnessLabel";
			this->brightnessLabel->Size = System::Drawing::Size(62, 13);
			this->brightnessLabel->TabIndex = 10;
			this->brightnessLabel->Text = L"Brightness :";
			// 
			// contrastLabel
			// 
			this->contrastLabel->AutoSize = true;
			this->contrastLabel->Location = System::Drawing::Point(4, 42);
			this->contrastLabel->Name = L"contrastLabel";
			this->contrastLabel->Size = System::Drawing::Size(52, 13);
			this->contrastLabel->TabIndex = 9;
			this->contrastLabel->Text = L"Contrast :";
			// 
			// redInput
			// 
			this->redInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->redInput->Location = System::Drawing::Point(2, 32);
			this->redInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->redInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, System::Int32::MinValue });
			this->redInput->Name = L"redInput";
			this->redInput->Size = System::Drawing::Size(34, 20);
			this->redInput->TabIndex = 10;
			// 
			// rgbBox
			// 
			this->rgbBox->Controls->Add(this->rgbButton);
			this->rgbBox->Controls->Add(this->blueLabel);
			this->rgbBox->Controls->Add(this->greenLabel);
			this->rgbBox->Controls->Add(this->redLabel);
			this->rgbBox->Controls->Add(this->blueInput);
			this->rgbBox->Controls->Add(this->greenInput);
			this->rgbBox->Controls->Add(this->redInput);
			this->rgbBox->Location = System::Drawing::Point(2, 40);
			this->rgbBox->Name = L"rgbBox";
			this->rgbBox->Size = System::Drawing::Size(92, 85);
			this->rgbBox->TabIndex = 11;
			this->rgbBox->TabStop = false;
			this->rgbBox->Text = L"RGB";
			this->rgbBox->Visible = false;
			// 
			// rgbButton
			// 
			this->rgbButton->Location = System::Drawing::Point(1, 58);
			this->rgbButton->Name = L"rgbButton";
			this->rgbButton->Size = System::Drawing::Size(85, 23);
			this->rgbButton->TabIndex = 16;
			this->rgbButton->Text = L"Apply";
			this->rgbButton->UseVisualStyleBackColor = true;
			this->rgbButton->Click += gcnew System::EventHandler(this, &easyGIMP::rgbButton_Click);
			// 
			// blueLabel
			// 
			this->blueLabel->AutoSize = true;
			this->blueLabel->Location = System::Drawing::Point(56, 16);
			this->blueLabel->Name = L"blueLabel";
			this->blueLabel->Size = System::Drawing::Size(17, 13);
			this->blueLabel->TabIndex = 15;
			this->blueLabel->Text = L"B:";
			// 
			// greenLabel
			// 
			this->greenLabel->AutoSize = true;
			this->greenLabel->Location = System::Drawing::Point(29, 16);
			this->greenLabel->Name = L"greenLabel";
			this->greenLabel->Size = System::Drawing::Size(18, 13);
			this->greenLabel->TabIndex = 14;
			this->greenLabel->Text = L"G:";
			// 
			// redLabel
			// 
			this->redLabel->AutoSize = true;
			this->redLabel->Location = System::Drawing::Point(0, 16);
			this->redLabel->Name = L"redLabel";
			this->redLabel->Size = System::Drawing::Size(18, 13);
			this->redLabel->TabIndex = 13;
			this->redLabel->Text = L"R:";
			// 
			// blueInput
			// 
			this->blueInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->blueInput->Location = System::Drawing::Point(59, 32);
			this->blueInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->blueInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, System::Int32::MinValue });
			this->blueInput->Name = L"blueInput";
			this->blueInput->Size = System::Drawing::Size(34, 20);
			this->blueInput->TabIndex = 12;
			// 
			// greenInput
			// 
			this->greenInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->greenInput->Location = System::Drawing::Point(32, 32);
			this->greenInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->greenInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, System::Int32::MinValue });
			this->greenInput->Name = L"greenInput";
			this->greenInput->Size = System::Drawing::Size(34, 20);
			this->greenInput->TabIndex = 11;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->toolsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1010, 24);
			this->menuStrip1->TabIndex = 12;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &easyGIMP::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Enabled = false;
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Enabled = false;
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &easyGIMP::saveAsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->zoomToolStripMenuItem,
					this->undoToolStripMenuItem, this->undoAllToolStripMenuItem, this->blurToolStripMenuItem, this->turnGrayToolStripMenuItem, this->detectEdgesToolStripMenuItem,
					this->resizeToolStripMenuItem, this->rGBToolStripMenuItem, this->contrastBrightnessToolStripMenuItem
			});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// zoomToolStripMenuItem
			// 
			this->zoomToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->zoomPlusToolStripMenuItem2,
					this->zoomMinusToolStripMenuItem1
			});
			this->zoomToolStripMenuItem->Name = L"zoomToolStripMenuItem";
			this->zoomToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->zoomToolStripMenuItem->Text = L"Zoom";
			// 
			// zoomPlusToolStripMenuItem2
			// 
			this->zoomPlusToolStripMenuItem2->Name = L"zoomPlusToolStripMenuItem2";
			this->zoomPlusToolStripMenuItem2->Size = System::Drawing::Size(117, 22);
			this->zoomPlusToolStripMenuItem2->Text = L"Zoom +";
			this->zoomPlusToolStripMenuItem2->Click += gcnew System::EventHandler(this, &easyGIMP::zoomPlusToolStripMenuItem2_Click);
			// 
			// zoomMinusToolStripMenuItem1
			// 
			this->zoomMinusToolStripMenuItem1->Name = L"zoomMinusToolStripMenuItem1";
			this->zoomMinusToolStripMenuItem1->Size = System::Drawing::Size(117, 22);
			this->zoomMinusToolStripMenuItem1->Text = L"Zoom -";
			this->zoomMinusToolStripMenuItem1->Click += gcnew System::EventHandler(this, &easyGIMP::zoomMinusToolStripMenuItem1_Click);
			// 
			// undoToolStripMenuItem
			// 
			this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
			this->undoToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->undoToolStripMenuItem->Text = L"Undo";
			this->undoToolStripMenuItem->Click += gcnew System::EventHandler(this, &easyGIMP::undoToolStripMenuItem_Click);
			// 
			// undoAllToolStripMenuItem
			// 
			this->undoAllToolStripMenuItem->Name = L"undoAllToolStripMenuItem";
			this->undoAllToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->undoAllToolStripMenuItem->Text = L"Undo All";
			this->undoAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &easyGIMP::undoAllToolStripMenuItem_Click);
			// 
			// blurToolStripMenuItem
			// 
			this->blurToolStripMenuItem->Name = L"blurToolStripMenuItem";
			this->blurToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->blurToolStripMenuItem->Text = L"Blur";
			this->blurToolStripMenuItem->Click += gcnew System::EventHandler(this, &easyGIMP::blurToolStripMenuItem_Click);
			// 
			// turnGrayToolStripMenuItem
			// 
			this->turnGrayToolStripMenuItem->Name = L"turnGrayToolStripMenuItem";
			this->turnGrayToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->turnGrayToolStripMenuItem->Text = L"Turn Gray";
			this->turnGrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &easyGIMP::turnGrayToolStripMenuItem_Click);
			// 
			// detectEdgesToolStripMenuItem
			// 
			this->detectEdgesToolStripMenuItem->Name = L"detectEdgesToolStripMenuItem";
			this->detectEdgesToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->detectEdgesToolStripMenuItem->Text = L"Detect Edges";
			this->detectEdgesToolStripMenuItem->Click += gcnew System::EventHandler(this, &easyGIMP::detectEdgesToolStripMenuItem_Click);
			// 
			// resizeToolStripMenuItem
			// 
			this->resizeToolStripMenuItem->Name = L"resizeToolStripMenuItem";
			this->resizeToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->resizeToolStripMenuItem->Text = L"Resize";
			this->resizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &easyGIMP::resizeToolStripMenuItem_Click);
			// 
			// rGBToolStripMenuItem
			// 
			this->rGBToolStripMenuItem->Name = L"rGBToolStripMenuItem";
			this->rGBToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->rGBToolStripMenuItem->Text = L"RGB";
			this->rGBToolStripMenuItem->Click += gcnew System::EventHandler(this, &easyGIMP::rGBToolStripMenuItem_Click);
			// 
			// contrastBrightnessToolStripMenuItem
			// 
			this->contrastBrightnessToolStripMenuItem->Name = L"contrastBrightnessToolStripMenuItem";
			this->contrastBrightnessToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->contrastBrightnessToolStripMenuItem->Text = L"Contrast/Brightness";
			this->contrastBrightnessToolStripMenuItem->Click += gcnew System::EventHandler(this, &easyGIMP::contrastBrightnessToolStripMenuItem_Click);
			// 
			// openImageDialog
			// 
			this->openImageDialog->FileName = L"openFileDialog1";
			// 
			// input_height
			// 
			this->input_height->Location = System::Drawing::Point(6, 20);
			this->input_height->Name = L"input_height";
			this->input_height->Size = System::Drawing::Size(81, 20);
			this->input_height->TabIndex = 8;
			this->input_height->Text = L"Height:";
			this->input_height->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// input_width
			// 
			this->input_width->Location = System::Drawing::Point(6, 46);
			this->input_width->Name = L"input_width";
			this->input_width->Size = System::Drawing::Size(81, 20);
			this->input_width->TabIndex = 9;
			this->input_width->Text = L"Width:";
			this->input_width->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// play_resize
			// 
			this->play_resize->Font = (gcnew System::Drawing::Font(L"Goudy Stout", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->play_resize->Location = System::Drawing::Point(6, 69);
			this->play_resize->Name = L"play_resize";
			this->play_resize->Size = System::Drawing::Size(81, 31);
			this->play_resize->TabIndex = 10;
			this->play_resize->Text = L"⏵";
			this->play_resize->UseVisualStyleBackColor = true;
			this->play_resize->Click += gcnew System::EventHandler(this, &easyGIMP::play_Click);
			// 
			// label_for_Canny
			// 
			this->label_for_Canny->AutoSize = true;
			this->label_for_Canny->Location = System::Drawing::Point(6, 18);
			this->label_for_Canny->Name = L"label_for_Canny";
			this->label_for_Canny->Size = System::Drawing::Size(129, 52);
			this->label_for_Canny->TabIndex = 16;
			this->label_for_Canny->Text = L"Enter the two thresholds\r\nand the kernel size for \r\nthe Canny edge detection\r\nand"
				L" click play";
			// 
			// input_upper_threshold
			// 
			this->input_upper_threshold->Location = System::Drawing::Point(9, 112);
			this->input_upper_threshold->Name = L"input_upper_threshold";
			this->input_upper_threshold->Size = System::Drawing::Size(113, 20);
			this->input_upper_threshold->TabIndex = 14;
			this->input_upper_threshold->Text = L"Upper threshold:";
			this->input_upper_threshold->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// input_lower_threshold
			// 
			this->input_lower_threshold->Location = System::Drawing::Point(9, 80);
			this->input_lower_threshold->Name = L"input_lower_threshold";
			this->input_lower_threshold->Size = System::Drawing::Size(113, 20);
			this->input_lower_threshold->TabIndex = 13;
			this->input_lower_threshold->Text = L"Lower threshold:";
			this->input_lower_threshold->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// input_kernel_size
			// 
			this->input_kernel_size->Location = System::Drawing::Point(9, 138);
			this->input_kernel_size->Name = L"input_kernel_size";
			this->input_kernel_size->Size = System::Drawing::Size(113, 20);
			this->input_kernel_size->TabIndex = 17;
			this->input_kernel_size->Text = L"Kernel size:";
			this->input_kernel_size->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// play_Canny
			// 
			this->play_Canny->Font = (gcnew System::Drawing::Font(L"Goudy Stout", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->play_Canny->Location = System::Drawing::Point(9, 164);
			this->play_Canny->Name = L"play_Canny";
			this->play_Canny->Size = System::Drawing::Size(113, 31);
			this->play_Canny->TabIndex = 18;
			this->play_Canny->Text = L"⏵";
			this->play_Canny->UseVisualStyleBackColor = true;
			this->play_Canny->Click += gcnew System::EventHandler(this, &easyGIMP::play_Canny_Click);
			// 
			// edegeDetectionBox
			// 
			this->edegeDetectionBox->Controls->Add(this->label_for_Canny);
			this->edegeDetectionBox->Controls->Add(this->input_lower_threshold);
			this->edegeDetectionBox->Controls->Add(this->input_upper_threshold);
			this->edegeDetectionBox->Controls->Add(this->play_Canny);
			this->edegeDetectionBox->Controls->Add(this->input_kernel_size);
			this->edegeDetectionBox->Location = System::Drawing::Point(2, 40);
			this->edegeDetectionBox->Name = L"edegeDetectionBox";
			this->edegeDetectionBox->Size = System::Drawing::Size(140, 216);
			this->edegeDetectionBox->TabIndex = 19;
			this->edegeDetectionBox->TabStop = false;
			this->edegeDetectionBox->Text = L"Edge Detection";
			this->edegeDetectionBox->Visible = false;
			// 
			// resizeBox
			// 
			this->resizeBox->Controls->Add(this->input_height);
			this->resizeBox->Controls->Add(this->input_width);
			this->resizeBox->Controls->Add(this->play_resize);
			this->resizeBox->Location = System::Drawing::Point(2, 40);
			this->resizeBox->Name = L"resizeBox";
			this->resizeBox->Size = System::Drawing::Size(99, 116);
			this->resizeBox->TabIndex = 20;
			this->resizeBox->TabStop = false;
			this->resizeBox->Text = L"Resize";
			this->resizeBox->Visible = false;
			// 
			// easyGIMP
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1010, 698);
			this->Controls->Add(this->resizeBox);
			this->Controls->Add(this->edegeDetectionBox);
			this->Controls->Add(this->rgbBox);
			this->Controls->Add(this->contrastAndBrightnessBox);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"easyGIMP";
			this->Text = L"easyGIMP";
			this->Load += gcnew System::EventHandler(this, &easyGIMP::easyGIMP_Load);
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &easyGIMP::easyGIMP_DragDrop);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &easyGIMP::easyGIMP_Enter);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contrastInput))->EndInit();
			this->contrastAndBrightnessBox->ResumeLayout(false);
			this->contrastAndBrightnessBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brightnessInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->redInput))->EndInit();
			this->rgbBox->ResumeLayout(false);
			this->rgbBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blueInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenInput))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->edegeDetectionBox->ResumeLayout(false);
			this->edegeDetectionBox->PerformLayout();
			this->resizeBox->ResumeLayout(false);
			this->resizeBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:

		System::Void easyGIMP_Load(System::Object^ sender, System::EventArgs^ e);

		System::Void easyGIMP_Enter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);

		void displayCVImage(MyImage* img);
		System::Void easyGIMP_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);

		void resizePictureBox(MyImage* img);

		System::Void input_OnFocus(System::Object^ sender, System::EventArgs^ e);

		System::Void play_Click(System::Object^ sender, System::EventArgs^ e);

		void checkImageDentified();
		System::Void play_Canny_Click(System::Object^ sender, System::EventArgs^ e);


		System::Void contrastAndBrightnessButton_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void rgbButton_Click(System::Object^ sender, System::EventArgs^ e);
		
		System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		 
		System::Void saveAsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void zoomPlusToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void zoomMinusToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void undoAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void blurToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void turnGrayToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void detectEdgesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void resizeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		void hideAllToolsMenu();
		System::Void rGBToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void contrastBrightnessToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void undoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
