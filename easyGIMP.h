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
	private: System::Windows::Forms::TextBox^ input_height;
	private: System::Windows::Forms::TextBox^ input_width;
	private: System::Windows::Forms::Button^ play_resize;






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
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(150, 78);
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
			this->decrease->Name = L"decrease";
			this->decrease->Size = System::Drawing::Size(36, 23);
			this->decrease->TabIndex = 2;
			this->decrease->Text = L"-";
			this->decrease->UseVisualStyleBackColor = true;
			this->decrease->Click += gcnew System::EventHandler(this, &easyGIMP::scaleDown);
			// 
			// Detect_edges
			// 
			this->Detect_edges->Location = System::Drawing::Point(12, 325);
			this->Detect_edges->Name = L"Detect_edges";
			this->Detect_edges->Size = System::Drawing::Size(115, 28);
			this->Detect_edges->TabIndex = 3;
			this->Detect_edges->Text = L"Detect edges";
			this->Detect_edges->UseVisualStyleBackColor = true;
			this->Detect_edges->Click += gcnew System::EventHandler(this, &easyGIMP::Detect_edges_Click);
			// 
			// Turn_gray
			// 
			this->Turn_gray->Location = System::Drawing::Point(12, 291);
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
			this->Undo_all->Name = L"Undo_all";
			this->Undo_all->Size = System::Drawing::Size(115, 27);
			this->Undo_all->TabIndex = 5;
			this->Undo_all->Text = L"Undo All";
			this->Undo_all->UseVisualStyleBackColor = true;
			this->Undo_all->Click += gcnew System::EventHandler(this, &easyGIMP::Undo_all_Click);
			// 
			// Save
			// 
			this->Save->Location = System::Drawing::Point(12, 374);
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
			this->Blur->Location = System::Drawing::Point(12, 257);
			this->Blur->Name = L"Blur";
			this->Blur->Size = System::Drawing::Size(115, 28);
			this->Blur->TabIndex = 7;
			this->Blur->Text = L"Blur";
			this->Blur->UseVisualStyleBackColor = true;
			this->Blur->Click += gcnew System::EventHandler(this, &easyGIMP::Blur_Click);
			// 
			// input_height
			// 
			this->input_height->Location = System::Drawing::Point(151, 40);
			this->input_height->Name = L"input_height";
			this->input_height->Size = System::Drawing::Size(81, 22);
			this->input_height->TabIndex = 8;
			this->input_height->Text = L"Height:";
			this->input_height->Visible = false;
			this->input_height->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// input_width
			// 
			this->input_width->Location = System::Drawing::Point(238, 40);
			this->input_width->Name = L"input_width";
			this->input_width->Size = System::Drawing::Size(81, 22);
			this->input_width->TabIndex = 9;
			this->input_width->Text = L"Width:";
			this->input_width->Visible = false;
			this->input_width->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// play_resize
			// 
			this->play_resize->Font = (gcnew System::Drawing::Font(L"Goudy Stout", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->play_resize->Location = System::Drawing::Point(323, 35);
			this->play_resize->Name = L"play_resize";
			this->play_resize->Size = System::Drawing::Size(30, 31);
			this->play_resize->TabIndex = 10;
			this->play_resize->Text = L"⏵";
			this->play_resize->UseVisualStyleBackColor = true;
			this->play_resize->Visible = false;
			this->play_resize->Click += gcnew System::EventHandler(this, &easyGIMP::play_Click);
			// 
			// lable_for_resize
			// 
			this->lable_for_resize->AutoSize = true;
			this->lable_for_resize->Location = System::Drawing::Point(150, 12);
			this->lable_for_resize->Name = L"lable_for_resize";
			this->lable_for_resize->Size = System::Drawing::Size(288, 16);
			this->lable_for_resize->TabIndex = 11;
			this->lable_for_resize->Text = L"Enter height and width for resizing and click play\r\n";
			this->lable_for_resize->Visible = false;
			// 
			// resize
			// 
			this->resize->Location = System::Drawing::Point(12, 74);
			this->resize->Name = L"resize";
			this->resize->Size = System::Drawing::Size(115, 27);
			this->resize->TabIndex = 12;
			this->resize->Text = L"Resize";
			this->resize->UseVisualStyleBackColor = true;
			this->resize->Click += gcnew System::EventHandler(this, &easyGIMP::resize_Click);
			// 
			// label_for_Canny
			// 
			this->label_for_Canny->AutoSize = true;
			this->label_for_Canny->Location = System::Drawing::Point(151, 11);
			this->label_for_Canny->Name = L"label_for_Canny";
			this->label_for_Canny->Size = System::Drawing::Size(526, 16);
			this->label_for_Canny->TabIndex = 16;
			this->label_for_Canny->Text = L"Enter the two thresholds and the kernel size for the Canny edge detection and ckl"
				L"ick play";
			this->label_for_Canny->Visible = false;
			// 
			// input_upper_threshold
			// 
			this->input_upper_threshold->Location = System::Drawing::Point(270, 40);
			this->input_upper_threshold->Name = L"input_upper_threshold";
			this->input_upper_threshold->Size = System::Drawing::Size(113, 22);
			this->input_upper_threshold->TabIndex = 14;
			this->input_upper_threshold->Text = L"Upper threshold:";
			this->input_upper_threshold->Visible = false;
			this->input_upper_threshold->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// input_lower_threshold
			// 
			this->input_lower_threshold->Location = System::Drawing::Point(151, 40);
			this->input_lower_threshold->Name = L"input_lower_threshold";
			this->input_lower_threshold->Size = System::Drawing::Size(113, 22);
			this->input_lower_threshold->TabIndex = 13;
			this->input_lower_threshold->Text = L"Lower threshold:";
			this->input_lower_threshold->Visible = false;
			this->input_lower_threshold->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// input_kernel_size
			// 
			this->input_kernel_size->Location = System::Drawing::Point(389, 40);
			this->input_kernel_size->Name = L"input_kernel_size";
			this->input_kernel_size->Size = System::Drawing::Size(76, 22);
			this->input_kernel_size->TabIndex = 17;
			this->input_kernel_size->Text = L"Kernel size:";
			this->input_kernel_size->Visible = false;
			this->input_kernel_size->Click += gcnew System::EventHandler(this, &easyGIMP::input_OnFocus);
			// 
			// play_Canny
			// 
			this->play_Canny->Font = (gcnew System::Drawing::Font(L"Goudy Stout", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->play_Canny->Location = System::Drawing::Point(475, 35);
			this->play_Canny->Name = L"play_Canny";
			this->play_Canny->Size = System::Drawing::Size(30, 31);
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
			this->ClientSize = System::Drawing::Size(1010, 698);
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
			this->Name = L"easyGIMP";
			this->Text = L"easyGIMP";
			this->Load += gcnew System::EventHandler(this, &easyGIMP::easyGIMP_Load);
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &easyGIMP::easyGIMP_DragDrop);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &easyGIMP::easyGIMP_Enter);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
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

};
}
