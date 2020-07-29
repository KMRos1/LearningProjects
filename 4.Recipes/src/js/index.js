import Search from './models/Search';
import $ from 'qquery';

const state = {}

const controlSearch = async () => {

    const query = $('.search__field').val();
    if (query) {
        // new search object and add to state
        state.search = new Search(query);

        // premaper ui for search 

        // search for reciepies
        await state.search.getResults();

        // render result on ui
        console.log(state.search.result)
    }

} 

$('.search').submit(e => {

    e.preventDefault();
    controlSearch();
  
});