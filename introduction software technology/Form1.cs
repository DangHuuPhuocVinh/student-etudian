using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ungdungquanlysanpham
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttNumber01_Click(object sender, EventArgs e)
        {
            txtValue01.Text = "Hello Mr Buoi";
        }

        private void buttNumber_Click(object sender, EventArgs e)
        {
            txtValue02.Text = "999";
            txtValue03.Text = "123";
        }

        private void txtValue02_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtValue03_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int soA = int.Parse(txtSoA.Test);
            int soB = int.Parse(txtSoB.Test);
            int ketQua = 0;
            switch (lblPhepTinh.Text)
            {
                case "+":
                    ketQua = soA + soB;
                    break;
                case "-":
                    ketQua = soA - soB;
                    break;
                case "*":


                case "/":
                    if (soB == 0)
                    {
                        lblKetQuan.Test = "Loi chia 0";
                        return;
                    }
                    else
                    {
                        ketQua = soA / soB;
                        break;
                    }
            }
        }
    }
}
