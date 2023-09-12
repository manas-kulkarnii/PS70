const urlParams = new URLSearchParams(window.location.search);
const first = urlParams.get('first');

if (first !== "False") {
    let proj = document.getElementById("projects");
    console.log(proj.children)
    Array.from(proj.children).forEach((elt, i) => {
        elt.classList.add(`appear${i + 1}`)
    });
    let title = document.getElementById("title");
    title.classList.add("typed");
    let intro = document.getElementById("intro");
    intro.classList.add("typed2");
}