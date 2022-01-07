using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UserApp.Model
{
    public class Database : DbContext
    {
        public DbSet<Products> Products { get; set; }
        public Database() { }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlite($"Data Source = d:\\programowanie\\PuProjekt\\PuProjekt\\UserApp\\Database\\database.db");
        }
    }
}