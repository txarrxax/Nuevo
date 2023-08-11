let slider = document.getElementById('slider');
let slider_max = slider.childElementCount;
let slider_val = 0;

function slide_next(){
	if (++slider_val == slider_max){
		slider_val = 0;
	}
	slider.style.left = '-' + slider_val + '00%';
}

function slide_prev(){
	if (--slider_val == -1){
		slider_val = slider_max - 1;
	}
	slider.style.left = '-' + slider_val + '00%';
}

function scrolltop(){
	window.scroll({
		behavior: 'smooth',
		left: 0,
		top: 0,
	});
}