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
    public class MoviesController : Controller
    {
        private ApplicationDbContext _movieContext;
        public MoviesController()
        {
            _movieContext=new ApplicationDbContext();
        }

        protected override void Dispose(bool disposing)
        {
            _movieContext.Dispose();
        }
     [Route("/Movies")]
        public ActionResult MoviesList()
        {
            
            var movies = _movieContext.Movies.ToList();

            var movieData = new MoviesList
            {
                Movies = movies

            };

            return View(movieData);
      
     }
     [Route("/Movies/MoviesDetails/{id}")]

     public ActionResult MoviesDetails(int id)
     {
         var details = _movieContext.Movies.SingleOrDefault(c => c.Id==id);
             return View(details);

     }



    }
}