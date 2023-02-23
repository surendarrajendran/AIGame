#pragma once
#include<string>
#include "GamePlay.h"
//#include <msclr\marshal_cppstd.h>


namespace FOAI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class SelectionPage : public System::Windows::Forms::Form
	{
	public:

		SelectionPage(void)
		{
			InitializeComponent();
			
			gt.add_node(_node("A1", "2222233333", 0, 0, 1));
			nodes_generated.push_back(_node("A1", "2222233333", 0, 0, 1));
			_node current_node = nodes_generated[0];
			

			while (nodes_generated.size() > 0) {
				current_node = nodes_generated[0];
				tree_creation('2', current_node);
				tree_creation('3', current_node);
				nodes_generated.erase(nodes_generated.begin());
			}

			assign_hvalues();
			gt.assign_descendents();

			current_game_node = gt.set_of_nodes[0];
			received_node = gt.set_of_nodes[0];

			label7->Text = gcnew String(gt.set_of_nodes[0].numbers.data());

			button1->Visible = false;
			button3->Visible = false;

			label2->Visible = false;
			label3->Visible = false;
			label4->Visible = false;
			label5->Visible = false;
			label8->Visible = false;
		}

	protected:

		~SelectionPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ ComputerClick;
	protected:

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label9;


	private: System::ComponentModel::IContainer^ components;


	private:



#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ComputerClick = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(4, 88);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(502, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Hello, Who should start the game\?";
			this->label1->Click += gcnew System::EventHandler(this, &SelectionPage::label1_Click);
			// 
			// ComputerClick
			// 
			this->ComputerClick->BackColor = System::Drawing::Color::Fuchsia;
			this->ComputerClick->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComputerClick->Location = System::Drawing::Point(96, 244);
			this->ComputerClick->Margin = System::Windows::Forms::Padding(4);
			this->ComputerClick->Name = L"ComputerClick";
			this->ComputerClick->Size = System::Drawing::Size(201, 87);
			this->ComputerClick->TabIndex = 1;
			this->ComputerClick->Text = L"Computer";
			this->ComputerClick->UseVisualStyleBackColor = false;
			this->ComputerClick->Click += gcnew System::EventHandler(this, &SelectionPage::ComputerClick_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(96, 375);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(201, 87);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Player";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &SelectionPage::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(757, 244);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(163, 32);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Player Score";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(723, 399);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(206, 32);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Computer Score";
			this->label3->Click += gcnew System::EventHandler(this, &SelectionPage::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(900, 244);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 32);
			this->label4->TabIndex = 5;
			this->label4->Click += gcnew System::EventHandler(this, &SelectionPage::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(911, 399);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 32);
			this->label5->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightCoral;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(96, 198);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(201, 87);
			this->button1->TabIndex = 7;
			this->button1->Text = L"2";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &SelectionPage::button1_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(96, 413);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(201, 87);
			this->button3->TabIndex = 8;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &SelectionPage::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(333, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(266, 42);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Current String:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(539, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(113, 42);
			this->label7->TabIndex = 10;
			this->label7->Text = L"label7";
			this->label7->Click += gcnew System::EventHandler(this, &SelectionPage::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(12, 125);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(436, 45);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Please choose your move";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Red;
			this->button4->Location = System::Drawing::Point(368, 575);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(173, 54);
			this->button4->TabIndex = 12;
			this->button4->Text = L"QUIT";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &SelectionPage::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(645, 575);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(173, 54);
			this->button5->TabIndex = 13;
			this->button5->Text = L"RESTART";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &SelectionPage::button5_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(778, 99);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(180, 37);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Score Table";
			// 
			// SelectionPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1217, 653);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->ComputerClick);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"SelectionPage";
			this->Text = L"SelectionPage";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void ComputerClick_Click(System::Object^ sender, System::EventArgs^ e) {

		ComputerClick->Visible = false;
		button2->Visible = false;
		
		button1->Visible = true;
		button3->Visible = true;

		label1->Visible = false;
		label2->Visible = true;
		label3->Visible = true;
		label4->Visible = true;
		label5->Visible = true;
		label8->Visible = true;

		gamestarter = 1;

		received_node = first_comp_move(current_game_node);
	
		MessageBox::Show("Computer is making its move.", "Computer First move", MessageBoxButtons::OK);

		label7->Text = gcnew String(received_node.numbers.data());
		label4->Text = gcnew String(received_node.p2.ToString());
		label5->Text = gcnew String(received_node.p1.ToString());

		current_game_node = received_node;

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		ComputerClick->Visible = false;
		button2->Visible = false;
		
		button1->Visible = true;
		button3->Visible = true;


		label1->Visible = false;
		label2->Visible = true;
		label3->Visible = true;
		label4->Visible = true;
		label5->Visible = true;
		label8->Visible = true;

		gamestarter = 2;

	}

	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		received_node = gameplay(current_game_node, '2', gamestarter);

		if (label7->Text != "")
		{
			if (received_node.id == current_game_node.id)
			{
				if (MessageBox::Show("Invalid number, Please choose a different one.", "Warning", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
					button3->Focus();
					return;
				}
			}
		}


		label7->Text = gcnew String(current_chosen_node.numbers.data());

		if (gamestarter == 2) {
			label4->Text = gcnew String(current_chosen_node.p1.ToString());
			label5->Text = gcnew String(current_chosen_node.p2.ToString());
		}
		else {
			label4->Text = gcnew String(current_chosen_node.p2.ToString());
			label5->Text = gcnew String(current_chosen_node.p1.ToString());
		}
		if (received_node.id != "00") {

			MessageBox::Show("Computer is making its move", "ComputerMove", MessageBoxButtons::OK);
			
			label7->Text = gcnew String(received_node.numbers.data());
		

			if (gamestarter == 2) {
				label4->Text = gcnew String(received_node.p1.ToString());
				label5->Text = gcnew String(received_node.p2.ToString());
			}
			else {
				label4->Text = gcnew String(received_node.p2.ToString());
				label5->Text = gcnew String(received_node.p1.ToString());
			}
		}



		if (label7->Text == "") {
			if (MessageBox::Show("Game over", "Result", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
			
					if (int::Parse(label5->Text) > int::Parse(label4->Text))
						MessageBox::Show("Computer Won", "Result", MessageBoxButtons::OK);
					else if (int::Parse(label5->Text) < int::Parse(label4->Text))
						MessageBox::Show("Congrats, you won", "Result", MessageBoxButtons::OK);
					else
						MessageBox::Show("Its a draw", "Result", MessageBoxButtons::OK);
			}
			
			if (MessageBox::Show("Would you like to play again", "Confirmation", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				Application::Restart();
			}
			else
			{
				MessageBox::Show("Thanks for playing!", "Thanks", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				this->Close();
			}

		}
		current_game_node = received_node;


	}

private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	received_node = gameplay(current_game_node, '3', gamestarter);

	if (label7->Text != "")
	{
		if (received_node.id == current_game_node.id)
		{
			if (MessageBox::Show("Invalid number, Please choose a different one.", "Warning", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
				button1->Focus();
				return;
			}
		}
	}

	
	label7->Text = gcnew String(current_chosen_node.numbers.data());

	if (gamestarter == 2) {
		label4->Text = gcnew String(current_chosen_node.p1.ToString());
		label5->Text = gcnew String(current_chosen_node.p2.ToString());
	}
	else {
		label4->Text = gcnew String(current_chosen_node.p2.ToString());
		label5->Text = gcnew String(current_chosen_node.p1.ToString());
	}
	if (received_node.id != "00") {
		MessageBox::Show("Computer is making its move", "ComputerMove", MessageBoxButtons::OK);
		label7->Text = gcnew String(received_node.numbers.data());

		if (gamestarter == 2) {
			label4->Text = gcnew String(received_node.p1.ToString());
			label5->Text = gcnew String(received_node.p2.ToString());
		}
		else {
			label4->Text = gcnew String(received_node.p2.ToString());
			label5->Text = gcnew String(received_node.p1.ToString());
		}
	}

	if (label7->Text == "") {
		if (MessageBox::Show("Game over", "Result", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
			if (int::Parse(label5->Text) > int::Parse(label4->Text))
				MessageBox::Show("Computer Won", "Result", MessageBoxButtons::OK);
			else if (int::Parse(label5->Text) < int::Parse(label4->Text))
				MessageBox::Show("Congrats, you won", "Result", MessageBoxButtons::OK);
			else
				MessageBox::Show("Its a draw", "Result", MessageBoxButtons::OK);
		
		}
		
		if (MessageBox::Show("Would you like to play again", "Confirmation", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			Application::Restart();
		}
		else
		{
			MessageBox::Show("Thanks for playing!", "Thanks", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			this->Close();
		}

	}
		current_game_node = received_node;
	
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Restart();
}
};
}
