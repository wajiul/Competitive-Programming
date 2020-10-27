using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance1
{
    class Parent
    {
        protected int b;
        internal int c;
        public Parent()
        {
            Console.WriteLine("Parent Constructor");
        }
        public Parent(int a)
        {
            Console.WriteLine("Parametarized Contructor of Parent");
        }
        public void M1()
        {
            Console.WriteLine("This is Parent class");
        }
        static Parent()
        {
            Console.WriteLine("static constructor of parent");
        }
    }
    class Child: Parent
    {
        public Child(int a): base(a) //  calling parametarized constructor of base class
        {
            Console.WriteLine("Parametarized constructor of Child");
        }
        public Child()
        {

            Console.WriteLine("Child Constructor");
            
        }
        public void M2()
        {
            Console.WriteLine("This is Child class");
        }
        static Child()
        {
            Console.WriteLine("static constructor of child");
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            Child ob = new Child(10);
            ob.M2();
            ob.M1();
            
        }
    }
}
