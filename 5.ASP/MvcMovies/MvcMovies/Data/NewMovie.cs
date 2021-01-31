using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using MvcMovies.Models;

namespace MvcMovies.Data
{
    public class NewMovie
    {
        public Movie newMovie { get; set; }
        public IEnumerable<Genre> genre { get; set; }
    }
}