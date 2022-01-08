using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UserApp.Model
{
    public class Products
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int Id { get; set; }

        [MaxLength(256)]
        public string ProductName { get; set; }

        public string ProductBarCode { get; set; }

        [Column(TypeName = "money")]
        public decimal ProductPrice { get; set; }

        public override string ToString()
        {
            return this.ProductName + " : " + this.ProductPrice + " zł";
        }
    }
}
