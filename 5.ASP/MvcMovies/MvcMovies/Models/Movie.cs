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
        [Required]
        [Display(Name = "Relase Date")]
        [DisplayFormat(ApplyFormatInEditMode = true, DataFormatString = "{0:yyyy-MM-dd}")]
        public DateTime? RelaseDate { get; set; }
        [Required]
        [Display(Name="Genre")]
        public byte GenreId { get; set; }
        public DateTime? DateAdded { get; set; }
         [Required]
        [Display(Name = "Number in stock")]
        [Range(1,10)]
        public byte InStock { get; set; }
    }
}