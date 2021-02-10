namespace MvcMovies.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class addValidationsToMovie : DbMigration
    {
        public override void Up()
        {
            AlterColumn("dbo.Movies", "RelaseDate", c => c.DateTime(nullable: false));
        }
        
        public override void Down()
        {
            AlterColumn("dbo.Movies", "RelaseDate", c => c.DateTime());
        }
    }
}
