using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using MvcMovies.Models;

namespace MvcMovies.Data
{
    public class NewCustomer
    {
        public IEnumerable<MembershipType> MembershipTypes{ get; set; }
        public Customer Customer { get; set; }


    }
}