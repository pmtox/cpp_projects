// Hide-on-scroll header with small debounce and show on upward scroll
(function(){
const header = document.querySelector('.site-header');
let lastScroll = window.pageYOffset || document.documentElement.scrollTop;
let ticking = false;


function onScroll(){
const current = window.pageYOffset || document.documentElement.scrollTop;
if (current <= 10) {
header.classList.remove('hide');
} else if (current > lastScroll) {
// scrolling down
header.classList.add('hide');
} else {
// scrolling up
header.classList.remove('hide');
}
lastScroll = current <= 0 ? 0 : current;
ticking = false;
}


window.addEventListener('scroll', () => {
if (!ticking) {
window.requestAnimationFrame(onScroll);
ticking = true;
}
}, {passive: true});
})();