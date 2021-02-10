﻿using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using Microsoft.Owin.Security.Provider;

namespace MvcMovies.Models
{
    public class Customer
    {
        public int Id { get; set; }
        [Required(ErrorMessage="Please enter name")]
        [StringLength(255)]
        public string Name { get; set; }
        public bool IsSubscribedToNewsletter { get; set; }
        public MembershipType MembershipType { get; set; }
        [Display(Name = "Type of membership")]
        public byte MembershipTypeId { get; set; }
        [Display(Name= "Date of birth")]
        [AdultValidation]
        public DateTime? Birthday { get; set; }
    }
    
}