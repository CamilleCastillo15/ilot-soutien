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
  window.onunload = function(){};

  $(function() {
    var timer_ajax_fieldtext;
    $('#calcu_dedu').keyup(function(value){
      var v = Math.min(37500,parseInt($(this).val()));
      var dedu = Math.floor(v*100/75);
      $(this).val(v);
      $('#calcu_don').val(dedu);
    })
    $('#calcu_dedu').change(function(value){
      var v = parseInt($(this).val());
      var dedu = Math.floor(v*100/75);
      $('#calcu_don').val(dedu);


    })
    $('#calcu_don').keyup(function(value){
      var v = Math.min(50000,parseInt($(this).val()));
      var dedu = Math.floor(v*75/100);
      $('#calcu_dedu').val(dedu);
    })
    $('#calcu_don').change(function(value){
      var v = Math.min(50000,parseInt($(this).val()));
      var dedu = Math.floor(v*75/100);
      $('#calcu_dedu').val(dedu);
    })
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
        if($('.ajax-notify')[0] || $('.form-item-unique-free input').is(':focus') || $('.form-item-monthly-free input').is(':focus') ) {
          $('input').blur();
          clearTimeout(timer_ajax_fieldtext);
          checkout_continue_try_to_continue_timeout = setTimeout(
            function() {
              $('.checkout-submit').click();
            }
          , 50);
          e.preventDefault();
        }
      });
    }
  });
  Drupal.behaviors.limitFormInputQuantity = {
	attach : function() {
    $("#edit-checkout-pane-info-don").appendTo("#commerce-checkout-form-checkout > div");

	  $('input.don.free').keypress(function(e) {

        var a = [];
        var k = e.which;

        for ( var i = 48; i < 58; i++) {
          a.push(i);
        }
        if (!(a.indexOf(k) >= 0) && k != 0 && k != 8 && k != 13) {
          e.preventDefault();
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);
