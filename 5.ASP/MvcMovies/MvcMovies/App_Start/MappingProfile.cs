using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using AutoMapper;
using MvcMovies.Models;
using MvcMovies.Dtos;

namespace MvcMovies.App_Start
{
    public class MappingProfile:Profile
    {
        public MappingProfile() {
            
            Mapper.CreateMap<Customer, CustomerDtos>();
            Mapper.CreateMap<CustomerDtos, Customer>();


        }

    }
}