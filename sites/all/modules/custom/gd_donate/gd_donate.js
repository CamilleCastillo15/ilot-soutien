/**
 * @file A JavaScript file for the theme.
 * 
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function($, Drupal, window, document, undefined) {
  $(function() {

	var don;
	$('body').on('click', 'div input.don', function() {
	   if($('div input.don').is(':checked')) { 
		 $('div input.don').attr('checked', false);
		 $(this).attr('checked', true);
	   }
	   if ($('div input.don.free').attr('checked') == true) {
	   $('div input.don.free').keyup( function() {
		   don = ($(this).val());
	
		});
	   }
	   else{
		  $('div input.don.free').attr('value','');
	      don = $(this).attr('value');
	   }
	});
	
	$('')
	
	var timer_ajax_fieldtext;
	$('body').on('keyup', 'div input.don.free',function() {
		$this = $(this);
		clearTimeout(timer_ajax_fieldtext);
		timer_ajax_fieldtext = setTimeout(function(){
			$this.change();
		},1500);
	});
	
	if ($('.checkout-submit')[0]) {
        var checkout_continue_try_to_continue_timeout;
        $('.checkout-submit').click(function(e){
            if (checkout_continue_try_to_continue_timeout) {
              clearTimeout(checkout_continue_try_to_continue_timeout);
            }
            if($('#gd_donate .ajax-progress')[0] || $('.form-item-unique-free input').is(':focus') || $('.form-item-monthly-free input').is(':focus') ) {
              $('input').blur();
              clearTimeout(timer_ajax_fieldtext);
              checkout_continue_try_to_continue_timeout = setTimeout(
                function() {
                  $('.checkout-submit').click();
                }
                , 50
              );
             
              e.preventDefault();
            }
        });
      }
  });
})(jQuery, Drupal, this, this.document);