import Search from './models/Search';
import $ from 'qquery';
import { elements, renderLoader, clearLoader } from './views/base'
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
        renderLoader(elements.searchRes);
        // search for reciepies
        await state.search.getResults();

        // render result on ui
        clearLoader();
        searchView.renderResults(state.search.result);
   
    }

} 

elements.searchForm.submit(e => {

    e.preventDefault();
    controlSearch();
  
});

elements.searchResPages.addEventListener('click', e => {
    const btn = e.target.closest('.btn-inline');
    if (btn) {
        const goToPage = parseInt(btn.dataset.goto, 10);
        searchView.clearResoults();
        searchView.renderResults(state.search.result, goToPage);
 
    }
});