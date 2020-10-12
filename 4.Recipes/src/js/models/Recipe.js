import axios from 'axios';
import { elements } from '../views/base';

export default class Recipe {

	constructor(id) {
		this.id = id;
	}

	async getRecipe() {
		try {
			const res = await axios(`https://forkify-api.herokuapp.com/api/get?rId=${this.id}`);
			
			this.title = res.data.recipe.title;
			this.author = res.data.recipe.publisher;
			this.img = res.data.recipe.image_url;
			this.url = res.data.recipe.source_url;
			this.indgredients = res.data.recipe.ingredients;
			this.servings = 4;
			this.time = 15;
			
		}
		catch (error) {
			console.log(error);
		}
	}


	//calcTime() {
	//	const numIng = this.indgredients.length;
	//	const periods = Math.ceil(numIng / 2);
	//	this.time = periods * 15;
	//}

}