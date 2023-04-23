#include <windows.h>
#include <gcroot.h>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace msclr::interop;
using namespace System::Drawing;


public ref class CalculatorForm : public System::Windows::Forms::Form
{
public:
    CalculatorForm()
    {
        InitializeComponent();
    }

private:
    TextBox^ input1;
    TextBox^ input2;
    Button^ addButton;
    Label^ resultLabel;

    void InitializeComponent()
    {
        input1 = gcnew TextBox();
        input1->Location = System::Drawing::Point(10, 10);
        input1->Size = System::Drawing::Size(50, 20);
        Controls->Add(input1);

        input2 = gcnew TextBox();
        input2->Location = System::Drawing::Point(70, 10);
        input2->Size = System::Drawing::Size(50, 20);
        Controls->Add(input2);

        addButton = gcnew Button();
        addButton->Text = "+";
        addButton->Location = System::Drawing::Point(130, 10);
        addButton->Size = System::Drawing::Size(30, 20);
        addButton->Click += gcnew EventHandler(this, &CalculatorForm::AddButton_Click);
        Controls->Add(addButton);

        resultLabel = gcnew Label();
        resultLabel->Text = "Result:";
        resultLabel->Location = System::Drawing::Point(10, 50);
        resultLabel->Size = System::Drawing::Size(200, 20);
        Controls->Add(resultLabel);
    }

    void AddButton_Click(Object^ sender, EventArgs^ e)
    {
        double value1 = Convert::ToDouble(input1->Text);
        double value2 = Convert::ToDouble(input2->Text);
        double sum = value1 + value2;
        resultLabel->Text = "Result: " + sum.ToString();
    }
};

public ref class MainForm : public System::Windows::Forms::Form
{
public:
    MainForm()
    {
        calculatorButton = gcnew Button();
        calculatorButton->Text = "Calculator";
        calculatorButton->Size = System::Drawing::Size(100, 30);
        calculatorButton->Location = System::Drawing::Point(50, 50);
        calculatorButton->Click += gcnew EventHandler(this, &MainForm::CalculatorButton_Click);
        Controls->Add(calculatorButton);

        app2Button = gcnew Button();
        app2Button->Text = "App2";
        app2Button->Size = System::Drawing::Size(100, 30);
        app2Button->Location = System::Drawing::Point(50, 100);
        app2Button->Click += gcnew EventHandler(this, &MainForm::App2Button_Click);
        Controls->Add(app2Button);
    }

private:
    Button^ calculatorButton;
    Button^ app2Button;

    void CalculatorButton_Click(Object^ sender, EventArgs^ e)
    {
        CalculatorForm^ calculatorForm = gcnew CalculatorForm();
        calculatorForm->ShowDialog();
    }

    void App2Button_Click(Object^ sender, EventArgs^ e)
    {
        // MySecondForm^ app2Form = gcnew MySecondForm();
        // App2Form^ app2Form = gcnew App2Form();
        // app2Form->ShowDialog();
    }

};


[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainForm());
    return 0;
}





