#include "MainForm.h"
using namespace RunningLine;

[STAThread]
int main(array<System::String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MainForm form;
	Application::Run(% form);
}