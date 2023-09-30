#include "MainForm.h"
#include "ParametersForm.h"

System::Void RunningLine::MainForm::panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	if (position >= 0)
	{
		int direction;
		int start_pos = position;
		int point1 = 0;
		int point2 = a - 1;
		if (position < point2)
		{
			direction = 0;
		}
		else if (position < 2 * point2)
		{
			direction = 1;
			start_pos %= point2;
		}
		else if (position < 3 * point2)
		{
			direction = 2;
			start_pos %= point2;
		}
		else
		{
			direction = 3;
			start_pos %= point2;
		}
		int len = l;
		bool isFirstDirection = true;
		while (len > 0)
		{
			int delta;
			if (len >= point2)
			{
				delta = point2 - 1;
			}
			else
			{
				delta = len - 1;
			}
			len = len - delta - 1;
			if (isFirstDirection)
			{
				len += start_pos;
				isFirstDirection = false;
			}
			else
			{
				start_pos = point1;
			}
			switch (direction)
			{
			case 0:
				e->Graphics->DrawLine(gcnew Pen(color), start_pos, point1, delta, point1);
				direction++;
				break;
			case 1:
				e->Graphics->DrawLine(gcnew Pen(color), point2, start_pos, point2, delta);
				direction++;
				break;
			case 2:
				e->Graphics->DrawLine(gcnew Pen(color), point2 - start_pos, point2, point2 - delta, point2);
				direction++;
				break;
			default:
				e->Graphics->DrawLine(gcnew Pen(color), point1, point2 - start_pos, point1, point2 - delta);
				direction = 0;
				break;
			}
		}
	}
}

System::Void RunningLine::MainForm::ïàðàìåòðûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	ParametersForm parametersForm(panel1->Width, panel1->Height);
	if (parametersForm.ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		l = parametersForm.GetL();
		a = parametersForm.GetA();
		color = parametersForm.GetColor();
		time = parametersForm.GetTime();
		max_pos = a * 4 - 4;
		çàïóñêToolStripMenuItem->Enabled = true;
	}
}

System::Void RunningLine::MainForm::çàïóñêToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer1->Interval = time;
	position = 0;
	StartStop(true);
}

System::Void RunningLine::MainForm::îÏðîãðàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ info = gcnew String("Íàçâàíèå: " + this->Text + "\nÂåðñèÿ: " + Application::ProductVersion + "\nÃîä: 2020\nÐàçðàáîò÷èê: Ñòóäåíò Ìîñóíîâ Ìàòâåé ãðóïïû ÈÍÁñ-1301");
	MessageBox::Show(this, info, "Î ïðîãðàììå", MessageBoxButtons::OK, MessageBoxIcon::Information);
	delete info;
}

System::Void RunningLine::MainForm::ïîìîùüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ info = gcnew String("Äëÿ çàäàíèÿ ïàðàìåòðîâ àíèìàöèè âûáåðèòå ïóíêò \"Ïàðàìåòðû\".\nÄëÿ çàïóñêà è îñòàíîâêè àíèìàöèè èñïîëüçóéòå ïóíêòû ìåíþ \"Çàïóñê\" è \"Îñòàíîâêà\".");
	MessageBox::Show(this, info, "Ïîìîùü", MessageBoxButtons::OK, MessageBoxIcon::Information);
	delete info;
}

System::Void RunningLine::MainForm::îñòàíîâêàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	position = -1;
	StartStop(false);
}

System::Void RunningLine::MainForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	position++;
	if (position == max_pos)
	{
		position = 0;
	}
	panel1->Invalidate();
}

void RunningLine::MainForm::StartStop(bool flag)
{
	panel1->Invalidate();
	timer1->Enabled = flag;
	çàïóñêToolStripMenuItem->Visible = !flag;
	îñòàíîâêàToolStripMenuItem->Visible = flag;
	ïàðàìåòðûToolStripMenuItem->Enabled = !flag;
}
