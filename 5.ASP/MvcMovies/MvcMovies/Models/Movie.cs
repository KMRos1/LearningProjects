using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;
using Microsoft.Owin.Security.Provider;

namespace MvcMovies.Models
{
    public class Movie
    {
        public int Id { get; set; }
        [Required]
        [StringLength(255)]
        public string Name { get; set; }
        public Genre Genre { get; set; }
        [Display(Name = "Relase Date")]
        [DisplayFormat(ApplyFormatInEditMode = true, DataFormatString = "{0:yyyy-MM-dd}")]
        public DateTime? RelaseDate { get; set; }
        [Display(Name="Genre")]
        public byte GenreId { get; set; }
        public DateTime? DateAdded { get; set; }
         [Display(Name = "Number in stock")]
        public byte InStock { get; set; }
    }
}