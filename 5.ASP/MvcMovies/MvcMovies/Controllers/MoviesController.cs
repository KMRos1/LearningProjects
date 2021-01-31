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
            
            var movies = _movieContext.Movies.Include(c=> c.Genre).ToList();

            var movieData = new MoviesList
            {
                Movies = movies

            };

            return View(movieData);
      
     }
     [Route("/Movies/MoviesDetails/{id}")]

     public ActionResult MoviesDetails(int id)
     {
         var details = _movieContext.Movies.Include(c=> c.Genre).SingleOrDefault(c => c.Id==id);
             return View(details);

     }
     public ActionResult NewMovie()
     {
         var genres = _movieContext.Genres.ToList();
         var newMovieView = new NewMovie
         {
            genre=genres
         };
         return View(newMovieView);
     }
     public ActionResult Save(Movie newMovie)
     {
         if (newMovie.Id == 0)
         {
             newMovie.DateAdded = DateTime.Now;
             _movieContext.Movies.Add(newMovie);

         }
         else {
             var movieModel=_movieContext.Movies.Single(c=>c.Id == newMovie.Id);
             movieModel.Name = newMovie.Name;
             movieModel.GenreId = newMovie.GenreId;
             movieModel.RelaseDate = newMovie.RelaseDate;
             movieModel.InStock = newMovie.InStock;

         }
         _movieContext.SaveChanges();
         return RedirectToAction("MoviesList", "Movies");
     }
     public ActionResult Edit(int id)
     {
         var movie = _movieContext.Movies.SingleOrDefault(c => c.Id == id);

         if (movie == null)
             return HttpNotFound();

         var viewModel = new NewMovie
         {

             newMovie=movie,
             genre=_movieContext.Genres.ToList()
         };
         return View("NewMovie", viewModel);
     }

    }

}