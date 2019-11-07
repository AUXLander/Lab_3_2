#pragma once
#include "Intera.h"
#include <math.h>
#include <algorithm>

double f(double x) {
	return 2 * cos(2 * x) + 2;
}
double F(double x) {
	return sin(2 * x) + 2 * x;
}

namespace Lab32 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Soution
	/// </summary>
	public ref class Soution : public System::Windows::Forms::Form
	{
	public:
		Soution(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Soution()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::Label^ labelResultEX;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::Label^ labelResultNM;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ labelResultV2;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Label^ labelResultV1;
	private: System::Windows::Forms::Label^ labelRatioV1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ editCount;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ editEndX;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ editStartX;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ mainChart;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::DataGridView^ DGV;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DGV_N;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DGV_NM;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DGV_MK_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DGV_MK_2;
	private: System::Windows::Forms::CheckBox^ checkMK2;
	private: System::Windows::Forms::CheckBox^ checkMK1;
	private: System::Windows::Forms::CheckBox^ checkNM;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;


	protected:






















	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Soution::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->checkMK2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkMK1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkNM = (gcnew System::Windows::Forms::CheckBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->labelResultEX = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->labelResultNM = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->labelResultV2 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->labelResultV1 = (gcnew System::Windows::Forms::Label());
			this->labelRatioV1 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->editCount = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->editEndX = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->editStartX = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->mainChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->DGV = (gcnew System::Windows::Forms::DataGridView());
			this->DGV_N = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DGV_NM = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DGV_MK_1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DGV_MK_2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainChart))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGV))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(639, 463);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->checkMK2);
			this->tabPage1->Controls->Add(this->checkMK1);
			this->tabPage1->Controls->Add(this->checkNM);
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->groupBox7);
			this->tabPage1->Controls->Add(this->groupBox6);
			this->tabPage1->Controls->Add(this->groupBox5);
			this->tabPage1->Controls->Add(this->groupBox4);
			this->tabPage1->Controls->Add(this->groupBox3);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->mainChart);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(631, 437);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Панель управления";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// checkMK2
			// 
			this->checkMK2->AutoSize = true;
			this->checkMK2->Checked = true;
			this->checkMK2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkMK2->Location = System::Drawing::Point(122, 377);
			this->checkMK2->Name = L"checkMK2";
			this->checkMK2->Size = System::Drawing::Size(51, 17);
			this->checkMK2->TabIndex = 24;
			this->checkMK2->Text = L"МК-2";
			this->checkMK2->UseVisualStyleBackColor = true;
			// 
			// checkMK1
			// 
			this->checkMK1->AutoSize = true;
			this->checkMK1->Checked = true;
			this->checkMK1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkMK1->Location = System::Drawing::Point(61, 377);
			this->checkMK1->Name = L"checkMK1";
			this->checkMK1->Size = System::Drawing::Size(51, 17);
			this->checkMK1->TabIndex = 23;
			this->checkMK1->Text = L"МК-1";
			this->checkMK1->UseVisualStyleBackColor = true;
			// 
			// checkNM
			// 
			this->checkNM->AutoSize = true;
			this->checkNM->Checked = true;
			this->checkNM->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkNM->Location = System::Drawing::Point(10, 377);
			this->checkNM->Name = L"checkNM";
			this->checkNM->Size = System::Drawing::Size(43, 17);
			this->checkNM->TabIndex = 22;
			this->checkNM->Text = L"ЧМ";
			this->checkNM->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(13, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 70);
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->labelResultEX);
			this->groupBox7->Location = System::Drawing::Point(4, 82);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(173, 37);
			this->groupBox7->TabIndex = 20;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Истинный ответ:";
			// 
			// labelResultEX
			// 
			this->labelResultEX->AutoSize = true;
			this->labelResultEX->Location = System::Drawing::Point(6, 16);
			this->labelResultEX->Name = L"labelResultEX";
			this->labelResultEX->Size = System::Drawing::Size(40, 13);
			this->labelResultEX->TabIndex = 9;
			this->labelResultEX->Text = L"Result:";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->labelResultNM);
			this->groupBox6->Location = System::Drawing::Point(4, 125);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(173, 37);
			this->groupBox6->TabIndex = 19;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Результаты ЧМ:";
			// 
			// labelResultNM
			// 
			this->labelResultNM->AutoSize = true;
			this->labelResultNM->Location = System::Drawing::Point(6, 16);
			this->labelResultNM->Name = L"labelResultNM";
			this->labelResultNM->Size = System::Drawing::Size(40, 13);
			this->labelResultNM->TabIndex = 9;
			this->labelResultNM->Text = L"Result:";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->labelResultV2);
			this->groupBox5->Location = System::Drawing::Point(4, 228);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(173, 37);
			this->groupBox5->TabIndex = 18;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Результаты МК-2:";
			// 
			// labelResultV2
			// 
			this->labelResultV2->AutoSize = true;
			this->labelResultV2->Location = System::Drawing::Point(6, 16);
			this->labelResultV2->Name = L"labelResultV2";
			this->labelResultV2->Size = System::Drawing::Size(40, 13);
			this->labelResultV2->TabIndex = 9;
			this->labelResultV2->Text = L"Result:";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->labelResultV1);
			this->groupBox4->Controls->Add(this->labelRatioV1);
			this->groupBox4->Location = System::Drawing::Point(4, 168);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(173, 54);
			this->groupBox4->TabIndex = 17;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Результаты МК-1:";
			// 
			// labelResultV1
			// 
			this->labelResultV1->AutoSize = true;
			this->labelResultV1->Location = System::Drawing::Point(6, 33);
			this->labelResultV1->Name = L"labelResultV1";
			this->labelResultV1->Size = System::Drawing::Size(40, 13);
			this->labelResultV1->TabIndex = 9;
			this->labelResultV1->Text = L"Result:";
			// 
			// labelRatioV1
			// 
			this->labelRatioV1->AutoSize = true;
			this->labelRatioV1->Location = System::Drawing::Point(6, 16);
			this->labelRatioV1->Name = L"labelRatioV1";
			this->labelRatioV1->Size = System::Drawing::Size(44, 13);
			this->labelRatioV1->TabIndex = 8;
			this->labelRatioV1->Text = L"RatioIn:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->editCount);
			this->groupBox3->Location = System::Drawing::Point(4, 323);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(173, 46);
			this->groupBox3->TabIndex = 16;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Количество точек";
			// 
			// editCount
			// 
			this->editCount->Location = System::Drawing::Point(6, 19);
			this->editCount->Name = L"editCount";
			this->editCount->Size = System::Drawing::Size(158, 20);
			this->editCount->TabIndex = 3;
			this->editCount->Text = L"1000";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->editEndX);
			this->groupBox2->Location = System::Drawing::Point(97, 271);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(80, 46);
			this->groupBox2->TabIndex = 15;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Конец";
			// 
			// editEndX
			// 
			this->editEndX->Location = System::Drawing::Point(6, 19);
			this->editEndX->Name = L"editEndX";
			this->editEndX->Size = System::Drawing::Size(65, 20);
			this->editEndX->TabIndex = 3;
			this->editEndX->Text = L"1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->editStartX);
			this->groupBox1->Location = System::Drawing::Point(4, 271);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(80, 46);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Начало";
			// 
			// editStartX
			// 
			this->editStartX->Location = System::Drawing::Point(6, 19);
			this->editStartX->Name = L"editStartX";
			this->editStartX->Size = System::Drawing::Size(65, 20);
			this->editStartX->TabIndex = 3;
			this->editStartX->Text = L"0";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(4, 403);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(173, 31);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Построить график";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Soution::button1_Click_1);
			// 
			// mainChart
			// 
			this->mainChart->BorderlineColor = System::Drawing::Color::Transparent;
			chartArea5->Name = L"ChartArea1";
			this->mainChart->ChartAreas->Add(chartArea5);
			this->mainChart->Location = System::Drawing::Point(185, 6);
			this->mainChart->Name = L"mainChart";
			this->mainChart->Size = System::Drawing::Size(440, 428);
			this->mainChart->TabIndex = 12;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->DGV);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(631, 437);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Таблица";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// DGV
			// 
			this->DGV->AllowUserToDeleteRows = false;
			this->DGV->BackgroundColor = System::Drawing::Color::White;
			this->DGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGV->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->DGV_N, this->DGV_NM,
					this->DGV_MK_1, this->DGV_MK_2
			});
			this->DGV->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DGV->Location = System::Drawing::Point(3, 3);
			this->DGV->MultiSelect = false;
			this->DGV->Name = L"DGV";
			this->DGV->ReadOnly = true;
			this->DGV->RowHeadersVisible = false;
			this->DGV->Size = System::Drawing::Size(625, 431);
			this->DGV->TabIndex = 0;
			// 
			// DGV_N
			// 
			this->DGV_N->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->DGV_N->HeaderText = L"N";
			this->DGV_N->Name = L"DGV_N";
			this->DGV_N->ReadOnly = true;
			this->DGV_N->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// DGV_NM
			// 
			this->DGV_NM->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->DGV_NM->HeaderText = L"ЧМ";
			this->DGV_NM->Name = L"DGV_NM";
			this->DGV_NM->ReadOnly = true;
			// 
			// DGV_MK_1
			// 
			this->DGV_MK_1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->DGV_MK_1->HeaderText = L"МК-1";
			this->DGV_MK_1->Name = L"DGV_MK_1";
			this->DGV_MK_1->ReadOnly = true;
			// 
			// DGV_MK_2
			// 
			this->DGV_MK_2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->DGV_MK_2->HeaderText = L"MK-2";
			this->DGV_MK_2->Name = L"DGV_MK_2";
			this->DGV_MK_2->ReadOnly = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->pictureBox2);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(631, 437);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Справка";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox2->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.ErrorImage")));
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(3, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(625, 431);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// Soution
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(639, 463);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Soution";
			this->Text = L"Методы вычисления интегралов";
			this->Load += gcnew System::EventHandler(this, &Soution::Soution_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainChart))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGV))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		unsigned int N = Convert::ToInt32(editCount->Text);

		double a = Convert::ToInt32(editStartX->Text);
		double b = Convert::ToInt32(editEndX->Text);

		mainChart->Series->Clear();

		auto unif_v1 = mainChart->Series->Add("Uniform_V1");
		auto unif_v2 = mainChart->Series->Add("Uniform_V2");
		auto graph = mainChart->Series->Add("Graph");
		auto stairs = mainChart->Series->Add("SquareStairs");

		graph->MarkerSize = 1;
		unif_v1->MarkerSize = 1;
		unif_v2->MarkerSize = 1;

		graph->ChartType = DataVisualization::Charting::SeriesChartType::Area;
		stairs->ChartType = DataVisualization::Charting::SeriesChartType::Line;
		unif_v1->ChartType = DataVisualization::Charting::SeriesChartType::Point;
		unif_v2->ChartType = DataVisualization::Charting::SeriesChartType::Point;

		graph->Color = Drawing::Color::FromArgb(100, 255, 0, 0);
		unif_v2->Color = Drawing::Color::FromArgb(255, 0, 255, 0);
		stairs->Color = Drawing::Color::FromArgb(255, 0, 0, 255);

		point MinMax = Integral::fMinfMax(f, a, b, N);

		MinMax.x = std::floor(MinMax.x);
		MinMax.y = std::ceil(MinMax.y);

		mainChart->ChartAreas[0]->AxisX->Minimum = a;
		mainChart->ChartAreas[0]->AxisX->Maximum = b;
		mainChart->ChartAreas[0]->AxisY->Minimum = MinMax.x;
		mainChart->ChartAreas[0]->AxisY->Maximum = MinMax.y;

		std::vector<point> uniformSquare = Integral::uniformRandomOnSquare({ a, MinMax.x }, { b, MinMax.y }, N);
		std::vector<point> squareStairs = Integral::squareStairs(f, a, b, N);

		std::vector<double> uniformLine = Integral::uniformRandomOnLine(a, b, N);

		double ratio_v1 = Integral::ratioIn(f, uniformSquare);
		double result_v1 = Integral::MonteCarlo_V1(f, a, b, uniformSquare);
		double result_v2 = Integral::MonteCarlo_V2(f, uniformLine);
		double result_NM = Integral::Numeric(f, a, b, N);
		double result_EX = F(b) - F(a);

		labelRatioV1->Text = String::Concat("RatioIn: ", Convert::ToString(ratio_v1));
		labelResultV1->Text = String::Concat("Result:  ", Convert::ToString(result_v1));
		labelResultV2->Text = String::Concat("Result:  ", Convert::ToString(result_v2));
		labelResultNM->Text = String::Concat("Result:  ", Convert::ToString(result_NM));
		labelResultEX->Text = String::Concat("Result:  ", Convert::ToString(result_EX));

		bool boolNM = Convert::ToBoolean(checkNM->Checked);
		bool boolMK1 = Convert::ToBoolean(checkMK1->Checked);
		bool boolMK2 = Convert::ToBoolean(checkMK2->Checked);

		double x = 0;
		double step = (b - a) / (double)N;

		stairs->Points->AddXY(squareStairs[0].x, 0);
		for (unsigned int i = 0; i < N; i++) {
			if (boolMK1) {
				unif_v1->Points->AddXY(uniformSquare[i].x, uniformSquare[i].y);
			}
			
			if (boolMK2) {
				unif_v2->Points->AddXY(uniformLine[i], 0.01);
			}

			if (boolNM) {
				stairs->Points->AddXY(squareStairs[i].x, squareStairs[i].y);
				stairs->Points->AddXY(squareStairs[i].x, squareStairs[i + 1].y);
			}

			x += step;
		}

		x = 0;
		N = std::max(N, (unsigned int)1000);
		step = (b - a) / (double)N;
		for (unsigned int i = 0; i < N; i++) {
			graph->Points->AddXY(a + x, f(a + x));
			x += step;
		}

		stairs->Points->AddXY(squareStairs[squareStairs.size() - 2].x, 0);


		DGV->Rows->Clear();

		for (unsigned int vN = 100, index = 0; vN <= 100000; vN *= 10) {
			DGV->Rows->Add();

			DGV->Rows[index]->Cells[0]->Value = vN;
			DGV->Rows[index]->Cells[1]->Value = Integral::Numeric(f, a, b, vN);			//nm
			DGV->Rows[index]->Cells[2]->Value = Integral::MonteCarlo_V1(f,a,b,vN);		//mk1
			DGV->Rows[index]->Cells[3]->Value = Integral::MonteCarlo_V2(f, a, b, vN);	//mk2

			index++;
		}

	}
	private: System::Void Soution_Load(System::Object^ sender, System::EventArgs^ e) {

		


	}
	};
}
