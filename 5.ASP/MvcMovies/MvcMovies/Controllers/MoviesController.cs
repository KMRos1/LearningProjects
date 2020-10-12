using System;
using System.Collections.Generic;
using System.Data.Entity.Core.Common.EntitySql;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MvcMovies.Data;
using MvcMovies.Models;

namespace MvcMovies.Controllers
{
    public class MoviesController : Controller
    {

        private List<Movie> getMovies()
        {
            return new List<Movie>
                {
                    new Movie{Id = 0, Name = "Iron Man"},
                    new Movie{Id = 1, Name = "Super Man"}
                };
        }
        public ActionResult MoviesList()
        {
            var movies = new MoviesList()
            {
                Movies = getMovies()
            };

            return View(movies);
        }
    }
}