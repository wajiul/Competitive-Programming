using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Propeties
{
    class Info
    {
        public string name;
        public int age;
    }
    class Dept
    {
        Info[] Student;
        public Dept()
        {
            Student = new Info[2]
            {
                new Info {name = "wajiul" , age = 23},
                new Info {name = "abc" , age = 24}
            };
        }
        public Info this[string name]
        {
            get
            {
                foreach(Info i in Student)
                {
                    if(i.name == name)
                    {
                        return i;
                    }
                }
                return null;
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Dept a = new Dept();
            Info b = a["wajiul"];
            Console.WriteLine(b.age);

        }
    }
}
