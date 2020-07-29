import axios from 'axios'

export default class Search {
    
    constructor(query) {
        this.query = query;
    }

    async getResults() {
        try {
            const res = await axios(`https://forkify-api.herokuapp.com/api/search?&q=${this.query}`);
            this.result = res.data.recipes;
          //console.log(this.result);
        }
        catch (error) {
            if (error.toString().includes('400')) {
                alert('No Recipes ');
            }
            else {
                alert(error);
            }
        }
    }
}