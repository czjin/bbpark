#include "admincontroller.h"
#include "admin.h"


AdminController::AdminController(const AdminController &)
    : ApplicationController()
{ }

void AdminController::dashboard()
{
    render("dashboard", "primary");
}

// Don't remove below this line
T_REGISTER_CONTROLLER(admincontroller)
