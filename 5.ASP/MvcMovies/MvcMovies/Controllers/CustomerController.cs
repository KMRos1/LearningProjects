using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MvcMovies.Data;
using MvcMovies.Models;

namespace MvcMovies.Controllers
{
    public class CustomerController : Controller
    {

        private ApplicationDbContext _context;

        public CustomerController()
        {
            _context = new ApplicationDbContext();
        }

        protected override void Dispose(bool disposing)
        {
            _context.Dispose();
        }

        //private List<Customer> getCustomers()
        //{
        //    return new List<Customer>
        //    {
        //      new Customer {Id = 0, Name = "John"},
        //        new Customer {Id = 1, Name = "Bob"},

        //    };
        //}

        // GET: Customer
        [Route("/Customers")]
        public ActionResult CustomerList()
        {
           
           var movie = new Movie() {Id = 0, Name = "iron"};
           var customers = _context.Customers.Include(c => c.MembershipType).ToList();
           var date1 = new MovieData
           {
            Movie = movie,
            Customers = customers
           };  
            return View(date1);
        }

        [Route("/Customer/Details/{id}")]
        public ActionResult Details(int id)
        {
           // if (id >= 0 && id < 2)
          //  {
              //  var customer = getCustomers().ElementAt(id);
              var customer = _context.Customers.Include(c => c.MembershipType).SingleOrDefault(c=>c.Id==id);
                return View(customer);
          //  }
           // else
           // {
             //   return HttpNotFound();
           // }

            
        }
    }
}