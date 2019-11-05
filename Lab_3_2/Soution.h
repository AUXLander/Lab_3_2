#pragma once
#include "Intera.h"
#include <math.h>

double f(double x) {
	return 2 * cos(2 * x) + 2;
}
double F(double x) {
	return sin(2 * x) + 2*x;
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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ mainChart;
	protected:

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ editStartX;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ editEndX;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ editCount;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Label^ labelRatioV1;
	private: System::Windows::Forms::Label^ labelResultV1;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ labelResultV2;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::Label^ labelResultNM;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::Label^ labelResultEX;
	private: System::Windows::Forms::PictureBox^ pictureBox1;



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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Soution::typeid));
			this->mainChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->editStartX = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->editEndX = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->editCount = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->labelResultV1 = (gcnew System::Windows::Forms::Label());
			this->labelRatioV1 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->labelResultV2 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->labelResultNM = (gcnew System::Windows::Forms::Label());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->labelResultEX = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainChart))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// mainChart
			// 
			this->mainChart->BorderlineColor = System::Drawing::Color::Transparent;
			chartArea1->Name = L"ChartArea1";
			this->mainChart->ChartAreas->Add(chartArea1);
			this->mainChart->Location = System::Drawing::Point(193, 12);
			this->mainChart->Name = L"mainChart";
			this->mainChart->Size = System::Drawing::Size(405, 400);
			this->mainChart->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 381);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 31);
			this->button1->TabIndex = 1;
			this->button1->Text = L"btnBuild";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Soution::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->editStartX);
			this->groupBox1->Location = System::Drawing::Point(12, 277);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(80, 46);
			this->groupBox1->TabIndex = 4;
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
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->editEndX);
			this->groupBox2->Location = System::Drawing::Point(96, 277);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(80, 46);
			this->groupBox2->TabIndex = 5;
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
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->editCount);
			this->groupBox3->Location = System::Drawing::Point(12, 329);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(164, 46);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Количество точек";
			// 
			// editCount
			// 
			this->editCount->Location = System::Drawing::Point(6, 19);
			this->editCount->Name = L"editCount";
			this->editCount->Size = System::Drawing::Size(148, 20);
			this->editCount->TabIndex = 3;
			this->editCount->Text = L"1000";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->labelResultV1);
			this->groupBox4->Controls->Add(this->labelRatioV1);
			this->groupBox4->Location = System::Drawing::Point(12, 174);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(164, 54);
			this->groupBox4->TabIndex = 7;
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
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->labelResultV2);
			this->groupBox5->Location = System::Drawing::Point(12, 234);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(164, 37);
			this->groupBox5->TabIndex = 8;
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
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->labelResultNM);
			this->groupBox6->Location = System::Drawing::Point(12, 131);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(164, 37);
			this->groupBox6->TabIndex = 9;
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
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->labelResultEX);
			this->groupBox7->Location = System::Drawing::Point(12, 88);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(164, 37);
			this->groupBox7->TabIndex = 10;
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
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 70);
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// Soution
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(614, 426);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->mainChart);
			this->Name = L"Soution";
			this->Text = L"Soution";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainChart))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		unsigned int N = Convert::ToInt32(editCount->Text);

		double a = Convert::ToInt32(editStartX->Text);
		double b = Convert::ToInt32(editEndX->Text);

		mainChart->Series->Clear();

		auto unif_v1 = mainChart->Series->Add("Uniform_V1");
		auto unif_v2 = mainChart->Series->Add("Uniform_V2");
		auto graph = mainChart->Series->Add("Graph");

		graph->MarkerSize = 1;
		unif_v1->MarkerSize = 1;
		unif_v2->MarkerSize = 1;

		graph->ChartType = DataVisualization::Charting::SeriesChartType::Area;
		unif_v1->ChartType = DataVisualization::Charting::SeriesChartType::Point;
		unif_v2->ChartType = DataVisualization::Charting::SeriesChartType::Point;

		graph->Color = Drawing::Color::FromArgb(100, 255, 0, 0);
		unif_v2->Color = Drawing::Color::FromArgb(255, 0, 255, 0);

		point MinMax = Integral::fMinfMax(f, a, b, N);

		MinMax.x = std::floor(MinMax.x);
		MinMax.y = std::ceil(MinMax.y);

		mainChart->ChartAreas[0]->AxisX->Minimum = a;
		mainChart->ChartAreas[0]->AxisX->Maximum = b;
		mainChart->ChartAreas[0]->AxisY->Minimum = MinMax.x;
		mainChart->ChartAreas[0]->AxisY->Maximum = MinMax.y;

		std::vector<point> uniformSquare = Integral::uniformRandomOnSquare({ a, MinMax.x }, { b, MinMax.y }, N);

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

		double x = 0;
		double step = (b - a) / (double)N;

		for (unsigned int i = 0; i < N; i++) {
			unif_v1->Points->AddXY(uniformSquare[i].x, uniformSquare[i].y);
			unif_v2->Points->AddXY(uniformLine[i], 0);

			graph->Points->AddXY(x, f(x));
			x += step;
		}
	}
	};
}
