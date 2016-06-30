(function ($) {

/**
 * Attach handlers to evaluate the strength of any password fields and to check
 * that its confirmation is correct.
 */
Drupal.behaviors.installForm = {
  attach: function (context, settings) {
    $('input.password-field, input.password-confirm').val('admin');
    $('.form-item-site-default-country select').val('FR');
    $('.form-submit').click();
  }
};


})(jQuery);
