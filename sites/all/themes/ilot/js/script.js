/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  /**
   * Core behavior for Administration menu.
   * 
   * Test whether there is an administration menu is in the output and execute
   * all registered behaviors.
   */
  Drupal.behaviors.ilot = {
    attach : function(context, settings) {
    	$('input, textarea').placeholder();
      $('.commerce_french_donate_wrapper .form-radios input:not(.screwed)').screwDefaultButtons({
        image : 'url("/sites/all/themes/ilot/images/radios.png")',
        width : 12,
        height : 12
      }).addClass('screwed');
      $('.customer_profile_billing_container .form-radios input:not(.screwed)').screwDefaultButtons({
          image : 'url("/sites/all/themes/ilot/images/radios4.png")',
          width : 12,
          height : 12
        }).addClass('screwed');
      //placeholderFallback();
      if (!$('.select_form_country')[0]) {
    	  $('select.country.form-select').wrap('<div class="select_form_country"></div>');
      }
      if ($('.fadein')[0]) {
        $('.fadein').stop().fadeOut(0).fadeIn(300);
      }
      if ($('input.unique.don.free')[0]) {
	    $('.commerce_french_donate_wrapper input:text').click(function(){
       
	    	$('.commerce_french_donate_wrapper input[type=text]').not($(this)).val('');
	    	$('.commerce_french_donate_wrapper input:radio').each(function(){

	    	  if ($(this).prop("checked") == true) {
            
	    		  $(this).prop("checked", false).parent().css("background-color",'#00a886');

	    	  }
	    	});
	    });
	    $('.commerce_french_donate_wrapper .styledRadio').click(function(){
	    	$('.commerce_french_donate_wrapper input[type=text]').val('');
	    });
      }
    }
  };

  $.clearTxt = function(e, ref) {
    if ($(e).val() === ref) {
      $(e).val('');
    }
  };

  $.resetTxt = function(e, ref) {
    if ($(e).val() === '') {
      $(e).val(ref);
    }
  };

  function placeholderFallback() {
    if (!$.browser.msie) {
      return;
    }
    $('input[placeholder]:empty').each(function() {
      var input = $(this);

      var val = input.attr('placeholder');

      input.focusin(function() {
        $.clearTxt(this, val);

      }).focusout(function() {
        $.resetTxt(this, val);

      }).val(val);
    });
  }
  /**
   * @} End of "defgroup admin_behaviors".
   */
  $(function(){
	  if (window.location.href.match(/\/(accueil)/)) {
		  $('.mosaique article').each(function(index){
			  var newlocation = $(this).find('a.read-more').attr('href');
			  $(this).click(function(){
				  window.location = newlocation;
			  });
		  });
		}
  });//end $(function(){}):
})(jQuery, Drupal, this, this.document);

(function($, Drupal, window, document, undefined)
    {
     $(function()
     {

       var menu_timeout;

       $('#navigation ul.menu li:not(.active-trail) ul.menu').hide();
       

       $('#navigation ul.menu li.expanded').mouseenter(function(e)
       {
         clearTimeout(menu_timeout);
         $('#navigation ul.menu ul.menu').hide();


         $('#navigation ul.menu li:not(.active-trail).active').removeClass('active');
         $(this).addClass('active').find('ul.menu').slideDown(200);
       });

       $('#navigation ul.menu li.expanded:not(.active-trail)').mouseleave(function(e)
       {
         clearTimeout(menu_timeout);
         menu_timeout = setTimeout(function()
         {
           $('#navigation ul.menu li:not(.active-trail).active').removeClass('active');
           $(' #navigation ul.menu ul.menu').hide();

         }, 150);
       });
     });
    })(jQuery, Drupal, this, this.document);


(function($, Drupal, window, document, undefined) {
/**
 * Overwrite drupal ajax before send
 * Prepare the Ajax request before it is sent.
 */

//if (typeof jQuery != 'undefined') {
//    // jQuery is loaded => print the version
//    alert(jQuery.fn.jquery);
//}

(function ($) {
    Drupal.behaviors.masBehavior = {
        attach: function (context, settings) {
            var mobile = (navigator.userAgent.match(/Android|webOS|iPhone|iPad|iPod|BlackBerry|BB|PlayBook|IEMobile|Windows Phone|Kindle|Silk|Opera Mini/i) ? true : false);
            var clickmethod = mobile ? "touchstart" : "click";
            var doc = $(document);
            var win = $(window);
            var burger = document.getElementsByClassName("burger")[0];
            var l_off = document.getElementsByClassName("l-off")[0];
            var l_shield= document.getElementsByClassName("l-shield")[0];
//            console.log(l_shield);
//            console.log("l_shield");
            var toggle = 1;
            $(window).on("resize",function(){
                l_shield.setAttribute("class", "l-shield");
                burger.setAttribute("class", "burger");
                l_off.setAttribute("class", "l-off h");
                toggle = 1;

            });
            $(".l-shield").on(clickmethod, function () {
                l_shield.setAttribute("class", "l-shield");
                burger.setAttribute("class", "burger");
                l_off.setAttribute("class", "l-off h");
                toggle = 1;
            });
            $(".burger").on(clickmethod, function () {
                if (toggle == 1) {
                    l_shield.setAttribute("class", "l-shield o");
                    burger.setAttribute("class", "burger o");
                    l_off.setAttribute("class", "l-off o");
                    toggle = 0;

                } else {
                    l_shield.setAttribute("class", "l-shield");
                    burger.setAttribute("class", "burger");
                    l_off.setAttribute("class", "l-off h");
                    toggle = 1;
                }
            });

//            console.log($("#views_slideshow_cycle_main_accueil_chiffres-default").height());

//            $(window).bind('resize', function (event) {

                console.log("mobile");

//                var windowWidth= $(window).width();
//                console.log(windowWidth);

//                if(windowWidth < 768) {

                  var Accordion = function(el, multiple) {
                        this.el = el || {};
                        this.multiple = multiple || false;

                        var link = this.el.find('.menu__item.is-expanded');

                        console.log(link);
                        link.on('click', {el: this.el, multiple: this.multiple},this.dropdown);
    //                  link.preventDefault();

                  }

                    Accordion.prototype.dropdown = function(e) {

//                        e.preventDefault();

                        var $el = e.data.el;

                        var $this = $(this).children('.menu');
                        console.log($this);

                        var $next = $this.next();

                        $next.slideToggle();
                        $this.slideToggle();
                        $this.parent().toggleClass('open');

    //                  $el.find('.menu .menu').slideUp().parent().removeClass('open');
    //                  $el.find('.menu .menu').not($next).slideUp().parent().removeClass('open');

                    }

                    $('.l-off .menu-block-wrapper .menu .menu').slideToggle();
                    var accordion = new Accordion($('.l-off .menu-block-wrapper > .menu'), false);
//
//                }

//            });
        }
    }

})(jQuery);

Drupal.ajax.prototype.beforeSend = function (xmlhttprequest, options) {
 // For forms without file inputs, the jQuery Form plugin serializes the form
 // values, and then calls jQuery's $.ajax() function, which invokes this
 // handler. In this circumstance, options.extraData is never used. For forms
 // with file inputs, the jQuery Form plugin uses the browser's normal form
 // submission mechanism, but captures the response in a hidden IFRAME. In this
 // circumstance, it calls this handler first, and then appends hidden fields
 // to the form to submit the values in options.extraData. There is no simple
 // way to know which submission mechanism will be used, so we add to extraData
 // regardless, and allow it to be ignored in the former case.

 if (this.form) {
   options.extraData = options.extraData || {};

   // Let the server know when the IFRAME submission mechanism is used. The
   // server can use this information to wrap the JSON response in a TEXTAREA,
   // as per http://jquery.malsup.com/form/#file-upload.
   options.extraData.ajax_iframe_upload = '1';

   // The triggering element is about to be disabled (see below), but if it
   // contains a value (e.g., a checkbox, textfield, select, etc.), ensure that
   // value is included in the submission. As per above, submissions that use
   // $.ajax() are already serialized prior to the element being disabled, so
   // this is only needed for IFRAME submissions.
   var v = $.fieldValue(this.element);
   if (v !== null) {
     options.extraData[this.element.name] = v;
   }
 }

 // Disable the element that received the change to prevent user interface
 // interaction while the Ajax request is in progress. ajax.ajaxing prevents
 // the element from triggering a new request, but does not prevent the user
 // from changing its value.
 $(this.element).addClass('progress-disabled').attr('disabled', true);

 // Insert progressbar or throbber.
 if (this.progress.type == 'bar') {
   var progressBar = new Drupal.progressBar('ajax-progress-' + this.element.id, eval(this.progress.update_callback), this.progress.method, eval(this.progress.error_callback));
   if (this.progress.message) {
     progressBar.setProgress(-1, this.progress.message);
   }
   if (this.progress.url) {
     progressBar.startMonitoring(this.progress.url, this.progress.interval || 1500);
   }
   this.progress.element = $(progressBar.element).addClass('ajax-progress ajax-progress-bar');
   this.progress.object = progressBar;
   $(this.element).after(this.progress.element);
 }
 else if (this.progress.type == 'throbber') {
   this.progress.element = $('<div class="ajax-notify"><div class="message">Chargement en cours, veuillez patentiez</div></div>');
   $('body .ajax-notifier-anchor').after(this.progress.element);
 }
};

Drupal.behaviors.ilot_form_messages = {
    timeout: null,
    attach : function() {
      // General (user account / login pages)
      var content_messages = $('#content div.messages.error');
      if (content_messages.length > 0) {
        this.attach_content(content_messages);
      }
    },
   
    attach_content : function(content_messages) {
      clearTimeout(Drupal.behaviors.ilot_form_messages.timeout);
      content_messages.show().stop().fadeOut(0).fadeIn(300);
      $('#main').stop().css('padding-top',
          content_messages.outerHeight(false) - 10 + 'px');
      Drupal.behaviors.ilot_form_messages.timeout = setTimeout(function(){
        content_messages.stop().fadeOut(600, function(){content_messages.remove();});
        $('#main').animate({'padding-top' : 0}, 600);
      },50000);
    }
  };

})(jQuery, Drupal, this, this.document);

(function ($) {
  Drupal.behaviors.btn_contact =  {
    attach: function(context, settings) {

      // Page Don : bouton savoir plus pointe vers Popup contact

     $('.field-name-field-actualite-video').click(function(){      
        $('embed').attr('src', $('embed').attr('src'));
        var url = $('embed').attr('src');
         window.open(url);
      });

    }
  };
})(jQuery);

(function ($) {
  Drupal.behaviors.others =  {
    attach: function(context, settings) {
      $('.menu-mlid-595 > a').attr("href", "mailto:maisons-accueil@ilot.asso.fr");
    }
  };
})(jQuery);


window.alert = function(a) {
	if (window.console) {
		console.log(a);
	}
};
