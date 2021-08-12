using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using Microsoft.Owin.Security.Provider;
using MvcMovies.Models;


namespace MvcMovies.Dtos
{
    public class CustomerDtos
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public bool IsSubscribedToNewsletter { get; set; }
        public byte MembershipTypeId { get; set; }
       // [AdultValidation]
        public DateTime? Birthday { get; set; }
    }
}