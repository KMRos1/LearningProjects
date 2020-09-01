import $ from 'qquery'
import { elements } from './base'
export const getInput = () => elements.searchInput.val();

export const clearInput = () => {
    elements.searchInput.val("");

};
export const clearResoults = () => {
    elements.searchResList.innerHTML = "";
    elements.searchResPages.innerHTML = "";
};
const limitTitle = (title, limit = 17) => {
    let newTitle = '';
    if (title.length > 17) {
        newTitle = title.slice(0, 17);
        return `${newTitle}...`;
    }
    else {
        return title;
    }    
    //const newTitle = [];
    //if (title.length > limit) {
    //    title.split(' ').reduce((acc, cur) => {
    //        if (acc + cur.length <= limit) {
    //            newTitle.push(cur);
    //        }
    //        return acc + cur.length
    //    });
    //}
    //return `${newTitle.join(' ')}...`;

  
};

const renderRecipe = recipe => {
    const markup = `
                <li>
                    <a class="results__link" href="#${recipe.recipe_id}">
                        <figure class="results__fig">
                            <img src="${recipe.image_url}" alt=${recipe.title}>
                        </figure>
                        <div class="results__data">
                            <h4 class="results__name">${limitTitle(recipe.title)}</h4>
                            <p class="results__author">${recipe.publisher}</p>
                        </div>
                    </a>
                </li>         
`;
    elements.searchResList.insertAdjacentHTML('beforeend', markup);
};

const createButtons = (page, type) => `
    
    <button class="btn-inline results__btn--${type}" data-goto=${type === 'prev' ? page - 1 : page + 1 }>
      <span>Page ${type=== 'prev' ? page - 1 : page + 1 }</span>
     <svg class="search__icon">
         <use href="img/icons.svg#icon-triangle-${type=== 'prev' ? 'left' : 'right'}"></use>
      </svg>
    </button>
`;


const renderButtons = (page, numResults, resPerPage) => {
    const pages = Math.ceil(numResults / resPerPage);
    let button;
    if (page === 1 && pages > 1) { 
        button = createButtons(page, 'next');
    } 
    else if (page < pages) {
        button = `
          ${createButtons(page, 'prev')}
          ${createButtons(page, 'next')}
`;
    }
        else if (page === pages) {
        button = createButtons(page, 'prev');
    }
    elements.searchResPages.insertAdjacentHTML('afterbegin', button);
};

export const renderResults = (recipies, page = 1, resPerPage = 10) => {
    //results
    const start = (page-1) * resPerPage;
    const end = page * resPerPage; 

    recipies.slice(start, end).forEach(renderRecipe);

    //buttons
    renderButtons(page, recipies.length, resPerPage);
};

