using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Data_hiding
{
    class Person
    {
        public string name { get; set; }
        public int age { get; set; }

        public void Work()
        {
            Console.WriteLine("Person Works ..");
        }
    }
    class Employee: Person
    {
        public int salary { get; set; }
        public new void Work()
        {
            Console.WriteLine("Employee Earn's ... ");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Employee k = new Employee();
            k.Work(); // Empoyee (k) hides Work() method of its Base class 
        }
    }
}
