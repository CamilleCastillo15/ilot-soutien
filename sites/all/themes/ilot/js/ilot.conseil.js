(function ($) {

    Drupal.behaviors.ilotHome = {

    attach: function (context, settings) {

    	var currentItem = null;
    	var currentBt = null;

         $('.img-admin').click(function(){
	    	
         	
         	if(currentItem != null){
         		currentItem.removeClass("active");
         	}
         	if(currentBt != null){
         		currentBt.removeClass("active");
         	}
         	
         	var go = $("#"+$(this).attr('id')+"_textes");
         	go.addClass("active");
         	$(this).addClass("active");

         	currentBt = $(this);

         	currentItem = go;

	    });

    }

};

})(jQuery);
