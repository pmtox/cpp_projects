// allow keyboard flip for accessibility: Enter toggles flip
document.querySelectorAll('.card').forEach(c=>{
c.addEventListener('keydown', e=>{
if(e.key === 'Enter' || e.key === ' '){
e.preventDefault();
c.classList.toggle('flipped');
}
});
});