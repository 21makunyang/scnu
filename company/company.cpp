#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "SalesMan.h"
#include "SalesManager.h"
#include "Technician.h"

using namespace std;
int main()
{
    Manager ma(1,"ma");
    cout<<ma.getSalary()<<'\n';
    SalesMan sa(2,"sa",1000000);
    cout<<sa.getSalary()<<'\n';
    SalesManager sag(3,"sag",1000000);
    cout<<sag.getSalary()<<'\n';
    Technician te(4,"te",10);
    cout<<te.getSalary()<<'\n';
    return 0;
}