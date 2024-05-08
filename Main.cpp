#include "easyGIMP.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create and run a new instance of your form
    Application::Run(gcnew Project::easyGIMP());
}
