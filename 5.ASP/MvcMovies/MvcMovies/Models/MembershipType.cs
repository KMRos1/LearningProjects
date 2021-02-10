using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace MvcMovies.Models
{
    public class MembershipType
    {
        public byte Id { get; set; }
        public short SignUpFree { get; set; }
        
        public byte DurationInMonths { get; set; }
        public byte DiscountRate { get; set; }
        [Required]
        [StringLength(255)]
       // [Display(Name = "Membership Type")]
        public string Name { get; set; }

        public static readonly byte Unknown = 0;
        public static readonly byte PayAsYouGo = 1;

    }
}