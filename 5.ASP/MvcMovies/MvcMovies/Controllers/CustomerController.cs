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

        public ActionResult New()
        {
            var membershiptypes = _context.MembershipTypes.ToList();
            var viewModel = new NewCustomer
            {
                MembershipTypes = membershiptypes

            };
            return View(viewModel);
        }
        [HttpPost]
        public ActionResult Save(NewCustomer viewModel)
        {
            if (viewModel.Customer.Id == 0)
            {
                _context.Customers.Add(viewModel.Customer);
            
            }
            else
            {
                var customerExist = _context.Customers.Single(c => c.Id == viewModel.Customer.Id);
                customerExist.Name = viewModel.Customer.Name;
                customerExist.MembershipTypeId = viewModel.Customer.MembershipTypeId;
                customerExist.IsSubscribedToNewsletter = viewModel.Customer.IsSubscribedToNewsletter;
                customerExist.Birthday = viewModel.Customer.Birthday;
            }
            _context.SaveChanges();
            return RedirectToAction("CustomerList", "Customer");
        }
      
        [Route("/Customers")]
        public ActionResult CustomerList()
        {
           
           var movie = new Movie() {Id = 0, Name = "iron"};
           var customers = _context.Customers.Include(c => c.MembershipType).ToList();
           var data1 = new MovieData
           {
            Movie = movie,
            Customers = customers
           };  
            return View(data1);
        }


        [Route("/Customer/Details/{id}")]
        public ActionResult Details(int id)
            {
          
              var customer = _context.Customers.Include(c => c.MembershipType).SingleOrDefault(c=>c.Id==id);
                return View(customer);
            }



        public ActionResult Edit(int id)
        {
            var customer = _context.Customers.SingleOrDefault(c => c.Id == id);
            
                if (customer==null)
                    return HttpNotFound();

            var viewModel = new NewCustomer {

                Customer=customer,
                MembershipTypes=_context.MembershipTypes.ToList()
            };
                return View("New", viewModel);
        }
        
    }
}