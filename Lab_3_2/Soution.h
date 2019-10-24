#pragma once
#include "Intera.h"
#include <math.h>

double f(double x) {
	return x;
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
	private: System::Windows::Forms::Label^ labelRatio;
	private: System::Windows::Forms::Label^ labelResult;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			this->mainChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->editStartX = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->editEndX = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->editCount = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->labelResult = (gcnew System::Windows::Forms::Label());
			this->labelRatio = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainChart))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->mainChart->ChartAreas->Add(chartArea1);
			this->mainChart->Location = System::Drawing::Point(337, 12);
			this->mainChart->Name = L"mainChart";
			this->mainChart->Size = System::Drawing::Size(405, 400);
			this->mainChart->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(201, 64);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 31);
			this->button1->TabIndex = 1;
			this->button1->Text = L"btnBuild";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Soution::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->editStartX);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(77, 46);
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
			this->groupBox2->Location = System::Drawing::Point(95, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(77, 46);
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
			this->groupBox3->Location = System::Drawing::Point(201, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(115, 46);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Количество точек";
			// 
			// editCount
			// 
			this->editCount->Location = System::Drawing::Point(6, 19);
			this->editCount->Name = L"editCount";
			this->editCount->Size = System::Drawing::Size(103, 20);
			this->editCount->TabIndex = 3;
			this->editCount->Text = L"1000";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->labelResult);
			this->groupBox4->Controls->Add(this->labelRatio);
			this->groupBox4->Location = System::Drawing::Point(12, 82);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(160, 100);
			this->groupBox4->TabIndex = 7;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Результаты:";
			// 
			// labelResult
			// 
			this->labelResult->AutoSize = true;
			this->labelResult->Location = System::Drawing::Point(6, 49);
			this->labelResult->Name = L"labelResult";
			this->labelResult->Size = System::Drawing::Size(37, 13);
			this->labelResult->TabIndex = 9;
			this->labelResult->Text = L"Result";
			// 
			// labelRatio
			// 
			this->labelRatio->AutoSize = true;
			this->labelRatio->Location = System::Drawing::Point(6, 27);
			this->labelRatio->Name = L"labelRatio";
			this->labelRatio->Size = System::Drawing::Size(41, 13);
			this->labelRatio->TabIndex = 8;
			this->labelRatio->Text = L"RatioIn";
			// 
			// Soution
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(753, 424);
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
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		unsigned int N = Convert::ToInt32(editCount->Text);

		double a = Convert::ToInt32(editStartX->Text);
		double b = Convert::ToInt32(editEndX->Text);
		
		mainChart->Series->Clear();

		auto uniform = mainChart->Series->Add("Uniform");
		auto graph = mainChart->Series->Add("Graph");

		graph->MarkerSize = 1;
		uniform->MarkerSize = 1;

		graph->ChartType = DataVisualization::Charting::SeriesChartType::Area;
		uniform->ChartType = DataVisualization::Charting::SeriesChartType::Point;

		graph->Color = Drawing::Color::FromArgb(100, 255, 0, 0);

		point MinMax = Integral::fMinfMax(f, a, b, N);

		MinMax.x = std::floor(MinMax.x);
		MinMax.y = std::ceil(MinMax.y);

		mainChart->ChartAreas[0]->AxisX->Minimum = a;
		mainChart->ChartAreas[0]->AxisX->Maximum = b;
		mainChart->ChartAreas[0]->AxisY->Minimum = MinMax.x;
		mainChart->ChartAreas[0]->AxisY->Maximum = MinMax.y;

		std::vector<point> unformSquare = Integral::uniformRandomOnSquare({ a, MinMax.x }, { b, MinMax.y }, N);
		double result = Integral::MonteCarlo_V1(f, a, b, unformSquare);
		double ratio = Integral::ratioIn(f, unformSquare);

		labelRatio->Text = Convert::ToString(ratio);
		labelResult->Text = Convert::ToString(result);

		double x = 0;
		double step = 1 / (double)N;
		
		for (auto point : unformSquare) {
			uniform->Points->AddXY(point.x, point.y);
			graph->Points->AddXY(x, f(x));

			x += step;
		}
	}
};
}
