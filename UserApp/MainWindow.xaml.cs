using Microsoft.Data.Sqlite;
using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Globalization;
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
using UserApp.Model;
using static Microsoft.EntityFrameworkCore.DbLoggerCategory;

namespace UserApp
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private const int codeLenght = 255;
        private SqliteConnection sqlConnection = new SqliteConnection("Data Source = d:\\programowanie\\PuProjekt\\UserApp\\Database\\database.db");
        private ObservableCollection<Products> productsList = new ObservableCollection<Products>();
        public MainWindow()
        {
            InitializeComponent();
            ltv_basket.ItemsSource = productsList;
            //SQL initial start data
            //sqlConnection.Open();
            //SqliteCommand sqlCommand = new SqliteCommand("INSERT INTO Products VALUES(6,'Chińska zupka błyskawiczna 150g','111001100011000000011110001111100110001111110011100111110011100000011111001101111',3.99)", sqlConnection);
            //var result = sqlCommand.ExecuteNonQuery();
            //sqlConnection.Close();
        }

        private void btn_close_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown(); //zamknięcie aplikacji
        }

        private void btn_reset_Click(object sender, RoutedEventArgs e)
        {
            productsList.Clear();
            lbl_sumMoney.Content = "0,00 zł";
        }

        private void btn_buy_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Dziekujemy za skorzystanie z naszych usług, twój koszyk jest wart: " + lbl_sumMoney.Content.ToString() + ".");
        }

        private void btn_scan_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog(); //utworzenie okna do przeglądania plików
            ofd.Filter = "Image Files|*.jpg;*.png;*.jpeg"; //ustawienie filtrów okna na dowolne pliki
            ofd.FilterIndex = 1; //ustawienie domyślnego filtru
            ofd.RestoreDirectory = true; //przywracanie wcześniej zamkniętego katalogu
            ofd.Multiselect = true; //ustawienie możliwości wyboru wielu plików z poziomu okna

            if (ofd.ShowDialog() == true)
            {
                FileInfo[] files = ofd.FileNames.Select(_file => new FileInfo(_file)).ToArray();

                foreach(var _file in files)
                {
                    StringBuilder sb = new StringBuilder(codeLenght);
                    decimal sumMoney = 0;

                    DllWrapper.GetCodeFromImg(_file.FullName, 0, sb);

                    //SQL Query
                    sqlConnection.Open();
                    SqliteCommand sqlCommand = new SqliteCommand("SELECT Id, ProductName, ProductBarCode, ProductPrice FROM Products WHERE ProductBarCode = '" + sb.ToString() +"'", sqlConnection);
                    SqliteDataReader sqlDataReader = sqlCommand.ExecuteReader();
                    while (sqlDataReader.Read())
                    {
                        Products product = new Products()
                        {
                            Id = sqlDataReader.GetInt32(0),
                            ProductName = sqlDataReader.GetString(1),
                            ProductBarCode = sqlDataReader.GetString(2),
                            ProductPrice = sqlDataReader.GetDecimal(3)
                        };

                        productsList.Add(product);
                        string s = lbl_sumMoney.Content.ToString();
                        s = s.Substring(0, s.Length - 3);
                        sumMoney = decimal.Parse(s, CultureInfo.GetCultureInfo("pl-PL"));
                        sumMoney += product.ProductPrice;
                        lbl_sumMoney.Content = sumMoney.ToString() + " zł";
                    }
                    sqlConnection.Close();
                }
            }
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
                        StringBuilder sb = new StringBuilder(codeLenght);
                        FileInfo fi = new FileInfo(_file);
                        decimal sumMoney = 0;

                        if (fi.Exists)
                        {
                            DllWrapper.GetCodeFromImg(fi.FullName, 0, sb);
                            //SQL Query
                            sqlConnection.Open();
                            SqliteCommand sqlCommand = new SqliteCommand("SELECT Id, ProductName, ProductBarCode, ProductPrice FROM Products WHERE ProductBarCode = '" + sb.ToString() + "'", sqlConnection);
                            SqliteDataReader sqlDataReader = sqlCommand.ExecuteReader();
                            while (sqlDataReader.Read())
                            {
                                Products product = new Products()
                                {
                                    Id = sqlDataReader.GetInt32(0),
                                    ProductName = sqlDataReader.GetString(1),
                                    ProductBarCode = sqlDataReader.GetString(2),
                                    ProductPrice = sqlDataReader.GetDecimal(3)
                                };

                                productsList.Add(product);
                                string s = lbl_sumMoney.Content.ToString();
                                s = s.Substring(0, s.Length - 3);
                                sumMoney = decimal.Parse(s, CultureInfo.GetCultureInfo("pl-PL") );
                                sumMoney += product.ProductPrice;
                                lbl_sumMoney.Content = sumMoney.ToString() + " zł";
                            }
                            sqlConnection.Close();
                            //MessageBox.Show(sb.ToString());
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

        private void grd_WindowBar_MouseDown(object sender, MouseButtonEventArgs e)
        {
            this.DragMove();
        }
    }
}
