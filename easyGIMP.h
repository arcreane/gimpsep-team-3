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
	private: System::Windows::Forms::Button^ increase;
	private: System::Windows::Forms::Button^ decrease;
	private: System::Windows::Forms::Button^ Detect_edges;
	private: System::Windows::Forms::Button^ Turn_gray;
	private: System::Windows::Forms::Button^ Undo_all;
	private: System::Windows::Forms::Button^ Save;
	private: System::Windows::Forms::Button^ Blur;
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



	private: System::Windows::Forms::Label^ lable_for_resize;
	private: System::Windows::Forms::Button^ resize;
	private: System::Windows::Forms::Label^ label_for_Canny;
	private: System::Windows::Forms::TextBox^ input_upper_threshold;
	private: System::Windows::Forms::TextBox^ input_lower_threshold;
	private: System::Windows::Forms::TextBox^ input_kernel_size;
	private: System::Windows::Forms::Button^ play_Canny;











	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->increase = (gcnew System::Windows::Forms::Button());
			this->decrease = (gcnew System::Windows::Forms::Button());
			this->Detect_edges = (gcnew System::Windows::Forms::Button());
			this->Turn_gray = (gcnew System::Windows::Forms::Button());
			this->Undo_all = (gcnew System::Windows::Forms::Button());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->Blur = (gcnew System::Windows::Forms::Button());
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
			this->input_height = (gcnew System::Windows::Forms::TextBox());
			this->input_width = (gcnew System::Windows::Forms::TextBox());
			this->play_resize = (gcnew System::Windows::Forms::Button());
			this->lable_for_resize = (gcnew System::Windows::Forms::Label());
			this->resize = (gcnew System::Windows::Forms::Button());
			this->label_for_Canny = (gcnew System::Windows::Forms::Label());
			this->input_upper_threshold = (gcnew System::Windows::Forms::TextBox());
			this->input_lower_threshold = (gcnew System::Windows::Forms::TextBox());
			this->input_kernel_size = (gcnew System::Windows::Forms::TextBox());
			this->play_Canny = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contrastInput))->BeginInit();
			this->contrastAndBrightnessBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brightnessInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->redInput))->BeginInit();
			this->rgbBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blueInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenInput))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(201, 96);
			this->pictureBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(233, 352);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &easyGIMP::easyGIMP_DragDrop);
			this->pictureBox->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &easyGIMP::easyGIMP_Enter);
			// 
			// increase
			// 
			this->increase->Location = System::Drawing::Point(91, 12);
			this->increase->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->increase->Name = L"increase";
			this->increase->Size = System::Drawing::Size(36, 23);
			this->increase->TabIndex = 1;
			this->increase->Text = L"+";
			this->increase->UseVisualStyleBackColor = true;
			this->increase->Click += gcnew System::EventHandler(this, &easyGIMP::scaleUp);
			// 
			// decrease
			// 
			this->decrease->Location = System::Drawing::Point(12, 12);
			this->decrease->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->decrease->Name = L"decrease";
			this->decrease->Size = System::Drawing::Size(36, 23);
			this->decrease->TabIndex = 2;
			this->decrease->Text = L"-";
			this->decrease->UseVisualStyleBackColor = true;
			this->decrease->Click += gcnew System::EventHandler(this, &easyGIMP::scaleDown);
			// 
			// Detect_edges
			// 
			this->Detect_edges->Location = System::Drawing::Point(11, 484);
			this->Detect_edges->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Detect_edges->Name = L"Detect_edges";
			this->Detect_edges->Size = System::Drawing::Size(115, 28);
			this->Detect_edges->TabIndex = 3;
			this->Detect_edges->Text = L"Detect edges";
			this->Detect_edges->UseVisualStyleBackColor = true;
			this->Detect_edges->Click += gcnew System::EventHandler(this, &easyGIMP::Detect_edges_Click);
			// 
			// Turn_gray
			// 
			this->Turn_gray->Location = System::Drawing::Point(11, 452);
			this->Turn_gray->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Turn_gray->Name = L"Turn_gray";
			this->Turn_gray->Size = System::Drawing::Size(115, 28);
			this->Turn_gray->TabIndex = 4;
			this->Turn_gray->Text = L"Turn gray";
			this->Turn_gray->UseVisualStyleBackColor = true;
			this->Turn_gray->Click += gcnew System::EventHandler(this, &easyGIMP::Turn_gray_Click);
			// 
			// Undo_all
			// 
			this->Undo_all->Location = System::Drawing::Point(12, 41);
			this->Undo_all->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Undo_all->Name = L"Undo_all";
			this->Undo_all->Size = System::Drawing::Size(115, 27);
			this->Undo_all->TabIndex = 5;
			this->Undo_all->Text = L"Undo All";
			this->Undo_all->UseVisualStyleBackColor = true;
			this->Undo_all->Click += gcnew System::EventHandler(this, &easyGIMP::Undo_all_Click);
			// 
			// Save
			// 
			this->Save->Location = System::Drawing::Point(11, 518);
			this->Save->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(115, 44);
			this->Save->TabIndex = 6;
			this->Save->Text = L"Save";
			this->Save->UseVisualStyleBackColor = true;
			this->Save->Visible = false;
			this->Save->Click += gcnew System::EventHandler(this, &easyGIMP::Save_Click);
			// 
			// Blur
			// 
			this->Blur->Location = System::Drawing::Point(11, 420);
			this->Blur->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Blur->Name = L"Blur";
			this->Blur->Size = System::Drawing::Size(115, 28);
			this->Blur->TabIndex = 7;
			this->Blur->Text = L"Blur";
			this->Blur->UseVisualStyleBackColor = true;
			this->Blur->Click += gcnew System::EventHandler(this, &easyGIMP::Blur_Click);
			// 
			// contrastInput
			// 
			this->contrastInput->DecimalPlaces = 1;
			this->contrastInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->contrastInput->Location = System::Drawing::Point(4, 71);
			this->contrastInput->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->contrastInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->contrastInput->Name = L"contrastInput";
			this->contrastInput->Size = System::Drawing::Size(115, 22);
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
			this->contrastAndBrightnessBox->Location = System::Drawing::Point(12, 110);
			this->contrastAndBrightnessBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->contrastAndBrightnessBox->Name = L"contrastAndBrightnessBox";
			this->contrastAndBrightnessBox->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->contrastAndBrightnessBox->Size = System::Drawing::Size(123, 191);
			this->contrastAndBrightnessBox->TabIndex = 9;
			this->contrastAndBrightnessBox->TabStop = false;
			this->contrastAndBrightnessBox->Text = L"Contrast and Brightness";
			// 
			// contrastAndBrightnessButton
			// 
			this->contrastAndBrightnessButton->Location = System::Drawing::Point(4, 153);
			this->contrastAndBrightnessButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->contrastAndBrightnessButton->Name = L"contrastAndBrightnessButton";
			this->contrastAndBrightnessButton->Size = System::Drawing::Size(113, 28);
			this->contrastAndBrightnessButton->TabIndex = 12;
			this->contrastAndBrightnessButton->Text = L"Apply";
			this->contrastAndBrightnessButton->UseVisualStyleBackColor = true;
			this->contrastAndBrightnessButton->Click += gcnew System::EventHandler(this, &easyGIMP::contrastAndBrightnessButton_Click);
			// 
			// brightnessInput
			// 
			this->brightnessInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->brightnessInput->Location = System::Drawing::Point(4, 119);
			this->brightnessInput->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->brightnessInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->brightnessInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, System::Int32::MinValue });
			this->brightnessInput->Name = L"brightnessInput";
			this->brightnessInput->Size = System::Drawing::Size(113, 22);
			this->brightnessInput->TabIndex = 11;
			// 
			// brightnessLabel
			// 
			this->brightnessLabel->AutoSize = true;
			this->brightnessLabel->Location = System::Drawing::Point(5, 100);
			this->brightnessLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->brightnessLabel->Name = L"brightnessLabel";
			this->brightnessLabel->Size = System::Drawing::Size(76, 16);
			this->brightnessLabel->TabIndex = 10;
			this->brightnessLabel->Text = L"Brightness :";
			// 
			// contrastLabel
			// 
			this->contrastLabel->AutoSize = true;
			this->contrastLabel->Location = System::Drawing::Point(5, 52);
			this->contrastLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->contrastLabel->Name = L"contrastLabel";
			this->contrastLabel->Size = System::Drawing::Size(62, 16);
			this->contrastLabel->TabIndex = 9;
			this->contrastLabel->Text = L"Contrast :";
			// 
			// redInput
			// 
			this->redInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->redInput->Location = System::Drawing::Point(3, 39);
			this->redInput->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->redInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->redInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, System::Int32::MinValue });
			this->redInput->Name = L"redInput";
			this->redInput->Size = System::Drawing::Size(45, 22);
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
			this->rgbBox->Location = System::Drawing::Point(12, 308);
			this->rgbBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->rgbBox->Name = L"rgbBox";
			this->rgbBox->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->rgbBox->Size = System::Drawing::Size(123, 105);
			this->rgbBox->TabIndex = 11;
			this->rgbBox->TabStop = false;
			this->rgbBox->Text = L"RGB";
			// 
			// rgbButton
			// 
			this->rgbButton->Location = System::Drawing::Point(1, 71);
			this->rgbButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->rgbButton->Name = L"rgbButton";
			this->rgbButton->Size = System::Drawing::Size(113, 28);
			this->rgbButton->TabIndex = 16;
			this->rgbButton->Text = L"Apply";
			this->rgbButton->UseVisualStyleBackColor = true;
			this->rgbButton->Click += gcnew System::EventHandler(this, &easyGIMP::rgbButton_Click);
			// 
			// blueLabel
			// 
			this->blueLabel->AutoSize = true;
			this->blueLabel->Location = System::Drawing::Point(75, 20);
			this->blueLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->blueLabel->Name = L"blueLabel";
			this->blueLabel->Size = System::Drawing::Size(19, 16);
			this->blueLabel->TabIndex = 15;
			this->blueLabel->Text = L"B:";
			// 
			// greenLabel
			// 
			this->greenLabel->AutoSize = true;
			this->greenLabel->Location = System::Drawing::Point(39, 20);
			this->greenLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->greenLabel->Name = L"greenLabel";
			this->greenLabel->Size = System::Drawing::Size(20, 16);
			this->greenLabel->TabIndex = 14;
			this->greenLabel->Text = L"G:";
			// 
			// redLabel
			// 
			this->redLabel->AutoSize = true;
			this->redLabel->Location = System::Drawing::Point(0, 20);
			this->redLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->redLabel->Name = L"redLabel";
			this->redLabel->Size = System::Drawing::Size(20, 16);
			this->redLabel->TabIndex = 13;
			this->redLabel->Text = L"R:";
			// 
			// blueInput
			// 
			this->blueInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->blueInput->Location = System::Drawing::Point(79, 39);
			this->blueInput->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->blueInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->blueInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, System::Int32::MinValue });
			this->blueInput->Name = L"blueInput";
			this->blueInput->Size = System::Drawing::Size(45, 22);
			this->blueInput->TabIndex = 12;
			// 
			// greenInput
			// 
			this->greenInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->greenInput->Location = System::Drawing::Point(43, 39);
			this->greenInput->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->greenInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->greenInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, System::Int32::MinValue });
			this->greenInput->Name = L"greenInput";
			this->greenInput->Size = System::Drawing::Size(45, 22);
			this->greenInput->TabIndex = 11;
			// 
			// input_height
			// 
			this->input_height->Location = System::Drawing::Point(201, 49);
			this->input_height->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->input_height->Name = L"input_height";
			this->input_height->Size = System::Drawing::Size(107, 22);
			this->input_height->TabIndex = 8;
			this->input_height->Text = L"Height:";
			this->input_height->Visible = false;
			this->input_height->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// input_width
			// 
			this->input_width->Location = System::Drawing::Point(317, 49);
			this->input_width->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->input_width->Name = L"input_width";
			this->input_width->Size = System::Drawing::Size(107, 22);
			this->input_width->TabIndex = 9;
			this->input_width->Text = L"Width:";
			this->input_width->Visible = false;
			this->input_width->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// play_resize
			// 
			this->play_resize->Font = (gcnew System::Drawing::Font(L"Goudy Stout", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->play_resize->Location = System::Drawing::Point(431, 43);
			this->play_resize->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->play_resize->Name = L"play_resize";
			this->play_resize->Size = System::Drawing::Size(40, 38);
			this->play_resize->TabIndex = 10;
			this->play_resize->Text = L"⏵";
			this->play_resize->UseVisualStyleBackColor = true;
			this->play_resize->Visible = false;
			this->play_resize->Click += gcnew System::EventHandler(this, &easyGIMP::play_Click);
			// 
			// lable_for_resize
			// 
			this->lable_for_resize->AutoSize = true;
			this->lable_for_resize->Location = System::Drawing::Point(200, 15);
			this->lable_for_resize->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lable_for_resize->Name = L"lable_for_resize";
			this->lable_for_resize->Size = System::Drawing::Size(288, 16);
			this->lable_for_resize->TabIndex = 11;
			this->lable_for_resize->Text = L"Enter height and width for resizing and click play\r\n";
			this->lable_for_resize->Visible = false;
			// 
			// resize
			// 
			this->resize->Location = System::Drawing::Point(12, 74);
			this->resize->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->resize->Name = L"resize";
			this->resize->Size = System::Drawing::Size(115, 28);
			this->resize->TabIndex = 12;
			this->resize->Text = L"Resize";
			this->resize->UseVisualStyleBackColor = true;
			this->resize->Click += gcnew System::EventHandler(this, &easyGIMP::resize_Click);
			// 
			// label_for_Canny
			// 
			this->label_for_Canny->AutoSize = true;
			this->label_for_Canny->Location = System::Drawing::Point(201, 14);
			this->label_for_Canny->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_for_Canny->Name = L"label_for_Canny";
			this->label_for_Canny->Size = System::Drawing::Size(526, 16);
			this->label_for_Canny->TabIndex = 16;
			this->label_for_Canny->Text = L"Enter the two thresholds and the kernel size for the Canny edge detection and ckl"
				L"ick play";
			this->label_for_Canny->Visible = false;
			// 
			// input_upper_threshold
			// 
			this->input_upper_threshold->Location = System::Drawing::Point(360, 49);
			this->input_upper_threshold->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->input_upper_threshold->Name = L"input_upper_threshold";
			this->input_upper_threshold->Size = System::Drawing::Size(149, 22);
			this->input_upper_threshold->TabIndex = 14;
			this->input_upper_threshold->Text = L"Upper threshold:";
			this->input_upper_threshold->Visible = false;
			this->input_upper_threshold->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// input_lower_threshold
			// 
			this->input_lower_threshold->Location = System::Drawing::Point(201, 49);
			this->input_lower_threshold->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->input_lower_threshold->Name = L"input_lower_threshold";
			this->input_lower_threshold->Size = System::Drawing::Size(149, 22);
			this->input_lower_threshold->TabIndex = 13;
			this->input_lower_threshold->Text = L"Lower threshold:";
			this->input_lower_threshold->Visible = false;
			this->input_lower_threshold->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// input_kernel_size
			// 
			this->input_kernel_size->Location = System::Drawing::Point(519, 49);
			this->input_kernel_size->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->input_kernel_size->Name = L"input_kernel_size";
			this->input_kernel_size->Size = System::Drawing::Size(100, 22);
			this->input_kernel_size->TabIndex = 17;
			this->input_kernel_size->Text = L"Kernel size:";
			this->input_kernel_size->Visible = false;
			this->input_kernel_size->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// play_Canny
			// 
			this->play_Canny->Font = (gcnew System::Drawing::Font(L"Goudy Stout", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->play_Canny->Location = System::Drawing::Point(633, 43);
			this->play_Canny->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->play_Canny->Name = L"play_Canny";
			this->play_Canny->Size = System::Drawing::Size(40, 38);
			this->play_Canny->TabIndex = 18;
			this->play_Canny->Text = L"⏵";
			this->play_Canny->UseVisualStyleBackColor = true;
			this->play_Canny->Visible = false;
			this->play_Canny->Click += gcnew System::EventHandler(this, &easyGIMP::play_Canny_Click);
			// 
			// easyGIMP
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1347, 859);
			this->Controls->Add(this->rgbBox);
			this->Controls->Add(this->contrastAndBrightnessBox);
			this->Controls->Add(this->play_Canny);
			this->Controls->Add(this->input_kernel_size);
			this->Controls->Add(this->label_for_Canny);
			this->Controls->Add(this->input_upper_threshold);
			this->Controls->Add(this->input_lower_threshold);
			this->Controls->Add(this->resize);
			this->Controls->Add(this->lable_for_resize);
			this->Controls->Add(this->play_resize);
			this->Controls->Add(this->input_width);
			this->Controls->Add(this->input_height);
			this->Controls->Add(this->Blur);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->Undo_all);
			this->Controls->Add(this->Turn_gray);
			this->Controls->Add(this->Detect_edges);
			this->Controls->Add(this->decrease);
			this->Controls->Add(this->increase);
			this->Controls->Add(this->pictureBox);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:

		System::Void easyGIMP_Load(System::Object^ sender, System::EventArgs^ e);

		System::Void easyGIMP_Enter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);

		void displayCVImage(MyImage* img);
		System::Void easyGIMP_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);

		System::Void scaleUp(System::Object^ sender, System::EventArgs^ e);

		void resizePictureBox(MyImage* img);
		System::Void scaleDown(System::Object^ sender, System::EventArgs^ e);

		System::Void Detect_edges_Click(System::Object^ sender, System::EventArgs^ e);
		
		System::Void Turn_gray_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void Undo_all_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void Save_Click(System::Object^ sender, System::EventArgs^ e);
		
		System::Void Blur_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void resize_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void input_OnFocus(System::Object^ sender, System::EventArgs^ e);

		System::Void play_Click(System::Object^ sender, System::EventArgs^ e);

		void checkImageDentified();
		System::Void play_Canny_Click(System::Object^ sender, System::EventArgs^ e);


		System::Void contrastAndBrightnessButton_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void rgbButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}