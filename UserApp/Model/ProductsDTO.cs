using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UserApp.Model
{
    public class ProductsDTO
    {
        public int Id { get; set; }
        public string ProductName { get; set; }

        public string ProductBarCode { get; set; }

        public decimal ProductPrice { get; set; }
    }
}
