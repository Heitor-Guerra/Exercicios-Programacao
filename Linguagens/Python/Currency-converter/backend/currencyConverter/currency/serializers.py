from rest_framework import serializers

from .models.currency import Currency


class CurrencySerializer(serializers.ModelSerializer):
    class Meta:
        model = Currency
        fields = ["name", "acronym", "symbol", "usd_rate"]
