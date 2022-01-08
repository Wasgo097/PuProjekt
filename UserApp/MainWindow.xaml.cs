using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace UserApp
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private const int codeLenght = 255;
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            //string result = null;
            //DllWrapper.GetCodeFromImg("d:\\programowanie\\PuProjekt\\examples\\6.jpg", 0, result);
            //Debug.Content = result;

            //DllWrapper.fibonacci_init(1, 1);
            //while (DllWrapper.fibonacci_next())
            //{
            //    Debug.Content = DllWrapper.fibonacci_current();
            //}
        }

        private void btn_close_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown(); //zamknięcie aplikacji
        }

        private void btn_reset_Click(object sender, RoutedEventArgs e)
        {
            
        }

        private void btn_buy_Click(object sender, RoutedEventArgs e)
        {

        }

        private void btn_scan_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog(); //utworzenie okna do przeglądania plików
            ofd.Filter = "Image Files|*.jpg;*.png;*.jpeg"; //ustawienie filtrów okna na dowolne pliki
            ofd.FilterIndex = 1; //ustawienie domyślnego filtru
            ofd.RestoreDirectory = true; //przywracanie wcześniej zamkniętego katalogu
            ofd.Multiselect = true; //ustawienie możliwości wyboru wielu plików z poziomu okna
        }

        private void btn_scan_Drop(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                // Note that you can have more than one file.
                string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);

                if(files != null && files.Length >= 1)
                {
                    foreach(string _file in files)
                    {
                        char[] result = new char[codeLenght];
                        StringBuilder sb = new StringBuilder(codeLenght);
                        FileInfo fi = new FileInfo(_file);

                        if (fi.Exists)
                        {
                            DllWrapper.GetCodeFromImg(fi.FullName, 0, sb);                   
                        }                                  
                    }
                }
            }
        }

        private void btn_scan_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effects = DragDropEffects.Copy;
            }
            else
            {
                e.Effects = DragDropEffects.None;
            }
        }
    }
}
