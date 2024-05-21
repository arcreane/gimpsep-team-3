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

	private: System::Windows::Forms::NumericUpDown^ brightnessInput;
	private: System::Windows::Forms::NumericUpDown^ redInput;
	private: System::Windows::Forms::GroupBox^ rgbBox;


	private: System::Windows::Forms::NumericUpDown^ blueInput;
	private: System::Windows::Forms::NumericUpDown^ greenInput;
	private: System::Windows::Forms::Label^ blueLabel;
	private: System::Windows::Forms::Label^ greenLabel;
	private: System::Windows::Forms::Label^ redLabel;
	private: System::Windows::Forms::Button^ rgbButton;














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
			this->pictureBox->Location = System::Drawing::Point(106, 10);
			this->pictureBox->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(175, 286);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &easyGIMP::easyGIMP_DragDrop);
			this->pictureBox->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &easyGIMP::easyGIMP_Enter);
			// 
			// increase
			// 
			this->increase->Location = System::Drawing::Point(68, 10);
			this->increase->Margin = System::Windows::Forms::Padding(2);
			this->increase->Name = L"increase";
			this->increase->Size = System::Drawing::Size(27, 19);
			this->increase->TabIndex = 1;
			this->increase->Text = L"+";
			this->increase->UseVisualStyleBackColor = true;
			this->increase->Click += gcnew System::EventHandler(this, &easyGIMP::scaleUp);
			// 
			// decrease
			// 
			this->decrease->Location = System::Drawing::Point(9, 10);
			this->decrease->Margin = System::Windows::Forms::Padding(2);
			this->decrease->Name = L"decrease";
			this->decrease->Size = System::Drawing::Size(27, 19);
			this->decrease->TabIndex = 2;
			this->decrease->Text = L"-";
			this->decrease->UseVisualStyleBackColor = true;
			this->decrease->Click += gcnew System::EventHandler(this, &easyGIMP::scaleDown);
			// 
			// Detect_edges
			// 
			this->Detect_edges->Location = System::Drawing::Point(9, 395);
			this->Detect_edges->Margin = System::Windows::Forms::Padding(2);
			this->Detect_edges->Name = L"Detect_edges";
			this->Detect_edges->Size = System::Drawing::Size(86, 23);
			this->Detect_edges->TabIndex = 3;
			this->Detect_edges->Text = L"Detect edges";
			this->Detect_edges->UseVisualStyleBackColor = true;
			this->Detect_edges->Click += gcnew System::EventHandler(this, &easyGIMP::Detect_edges_Click);
			// 
			// Turn_gray
			// 
			this->Turn_gray->Location = System::Drawing::Point(9, 368);
			this->Turn_gray->Margin = System::Windows::Forms::Padding(2);
			this->Turn_gray->Name = L"Turn_gray";
			this->Turn_gray->Size = System::Drawing::Size(86, 23);
			this->Turn_gray->TabIndex = 4;
			this->Turn_gray->Text = L"Turn gray";
			this->Turn_gray->UseVisualStyleBackColor = true;
			this->Turn_gray->Click += gcnew System::EventHandler(this, &easyGIMP::Turn_gray_Click);
			// 
			// Undo_all
			// 
			this->Undo_all->Location = System::Drawing::Point(9, 33);
			this->Undo_all->Margin = System::Windows::Forms::Padding(2);
			this->Undo_all->Name = L"Undo_all";
			this->Undo_all->Size = System::Drawing::Size(86, 22);
			this->Undo_all->TabIndex = 5;
			this->Undo_all->Text = L"Undo All";
			this->Undo_all->UseVisualStyleBackColor = true;
			this->Undo_all->Click += gcnew System::EventHandler(this, &easyGIMP::Undo_all_Click);
			// 
			// Save
			// 
			this->Save->Location = System::Drawing::Point(11, 422);
			this->Save->Margin = System::Windows::Forms::Padding(2);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(86, 36);
			this->Save->TabIndex = 6;
			this->Save->Text = L"Save";
			this->Save->UseVisualStyleBackColor = true;
			this->Save->Visible = false;
			this->Save->Click += gcnew System::EventHandler(this, &easyGIMP::Save_Click);
			// 
			// Blur
			// 
			this->Blur->Location = System::Drawing::Point(12, 341);
			this->Blur->Margin = System::Windows::Forms::Padding(2);
			this->Blur->Name = L"Blur";
			this->Blur->Size = System::Drawing::Size(86, 23);
			this->Blur->TabIndex = 7;
			this->Blur->Text = L"Blur";
			this->Blur->UseVisualStyleBackColor = true;
			this->Blur->Click += gcnew System::EventHandler(this, &easyGIMP::Blur_Click);
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
			this->contrastAndBrightnessBox->Location = System::Drawing::Point(9, 60);
			this->contrastAndBrightnessBox->Name = L"contrastAndBrightnessBox";
			this->contrastAndBrightnessBox->Size = System::Drawing::Size(92, 155);
			this->contrastAndBrightnessBox->TabIndex = 9;
			this->contrastAndBrightnessBox->TabStop = false;
			this->contrastAndBrightnessBox->Text = L"Contrast and Brightness";
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
			this->rgbBox->Location = System::Drawing::Point(9, 221);
			this->rgbBox->Name = L"rgbBox";
			this->rgbBox->Size = System::Drawing::Size(92, 85);
			this->rgbBox->TabIndex = 11;
			this->rgbBox->TabStop = false;
			this->rgbBox->Text = L"RGB";
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
			// easyGIMP
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(758, 567);
			this->Controls->Add(this->rgbBox);
			this->Controls->Add(this->contrastAndBrightnessBox);
			this->Controls->Add(this->Blur);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->Undo_all);
			this->Controls->Add(this->Turn_gray);
			this->Controls->Add(this->Detect_edges);
			this->Controls->Add(this->decrease);
			this->Controls->Add(this->increase);
			this->Controls->Add(this->pictureBox);
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
			this->ResumeLayout(false);

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

		System::Void contrastAndBrightnessButton_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void rgbButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
