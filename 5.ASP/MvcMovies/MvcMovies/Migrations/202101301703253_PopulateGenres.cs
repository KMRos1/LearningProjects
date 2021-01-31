namespace MvcMovies.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class PopulateGenres : DbMigration
    {
        public override void Up()
        {
            Sql("INSERT INTO Genres(Id, Name) VALUES (1,'Horror')");
            Sql("INSERT INTO Genres(Id, Name) VALUES (2,'Comedy')");
            Sql("INSERT INTO Genres(Id, Name) VALUES (3,'Action')");
        }
        
        public override void Down()
        {
        }
    }
}
