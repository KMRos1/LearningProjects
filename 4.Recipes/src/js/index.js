import Search from './models/Search';
import $ from 'qquery';
import { elements } from './views/base'
import * as searchView from './views/searchView'

const state = {}

const controlSearch = async () => {

    const query = searchView.getInput();
    if (query) {
        // new search object and add to state
        state.search = new Search(query);
        
        // prepare ui for search 
        searchView.clearInput();
        searchView.clearResoults();
        // search for reciepies
        await state.search.getResults();

        // render result on ui
        searchView.renderResults(state.search.result);
        console.log(state.search);
    }

} 

elements.searchForm.submit(e => {

    e.preventDefault();
    controlSearch();
  
});