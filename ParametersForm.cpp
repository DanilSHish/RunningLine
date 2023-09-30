#include "ParametersForm.h"
 
int RunningLine::ParametersForm::GetL()
{
	return l;
}

int RunningLine::ParametersForm::GetA()
{
	return a;
}

int RunningLine::ParametersForm::GetTime()
{
	return time;
}

System::Drawing::Color RunningLine::ParametersForm::GetColor()
{
	return color;
}

System::Void RunningLine::ParametersForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	DialogResult = System::Windows::Forms::DialogResult::OK;
}

System::Void RunningLine::ParametersForm::numericUpDown3_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	time = Convert::ToInt32(numericUpDown3->Value);
}

System::Void RunningLine::ParametersForm::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (colorDialog1->Color == Color::White)
		{
			color = Color::Black;
		}
		else
		{
			color = colorDialog1->Color;
		}
		pictureBox1->BackColor = color;
	}
}

System::Void RunningLine::ParametersForm::numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	l = Convert::ToInt32(numericUpDown1->Value);
}

System::Void RunningLine::ParametersForm::numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	a = Convert::ToInt32(numericUpDown2->Value);
	numericUpDown1->Maximum = (int)numericUpDown2->Value * 4 - 4 - 1;
}
